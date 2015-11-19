// Question: Round robin.
// Input: [0,1,3,9], [2,1,7,5], 2
// Expected return value: 1.0

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Job {
    int arrive;
    int execute;
    Job(int a, int e) : arrive(a), execute(e) {}
};

// Suppose the arrive is sorted.
double round_robin(vector<int> arrive, vector<int> execute, int q) {
    if (arrive.empty() || execute.empty() || arrive.size() != execute.size()) {
        return 0;
    }

    queue<Job> jobq;
    int next_job_id = 0;
    int wait_time = 0;
    int curr_time = 0;
    while (!jobq.empty() || next_job_id < arrive.size()) {
        if (jobq.empty()) {
            curr_time = arrive[next_job_id];
            jobq.push(Job(arrive[next_job_id], execute[next_job_id]));
            ++next_job_id;
        } else {
            Job job = jobq.front();
            jobq.pop();

            wait_time += (curr_time - job.arrive);
            curr_time += min(q, job.execute);
            for (; next_job_id < arrive.size(); ++next_job_id) {
                if (arrive[next_job_id] <= curr_time) {
                    jobq.push(Job(arrive[next_job_id], execute[next_job_id]));
                } else {
                    break;
                }
            }

            if (job.execute > q) {
                jobq.push(Job(curr_time, job.execute - q));
            }
        }
    }
    return (double)wait_time / arrive.size();
}

int main(int argc, char** argv) {
    vector<int> arrive;
    arrive.push_back(0);
    arrive.push_back(1);
    arrive.push_back(3);
    arrive.push_back(9);

    vector<int> execute;
    execute.push_back(2);
    execute.push_back(1);
    execute.push_back(7);
    execute.push_back(5);

    int q = 2;

    std::cout << round_robin(arrive, execute, q) << std::endl;

}
