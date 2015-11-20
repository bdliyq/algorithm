// Question: Shortest job first.

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Job {
    int arrive;
    int execute;
    Job(int a, int e) : arrive(a), execute(e) {}
};

bool operator < (const Job& j1, const Job& j2) {
    if (j1.execute == j2.execute) {
        return j1.arrive < j2.arrive;
    }
    return j1.execute < j2.execute;
}

double shortest_job_first(vector<int> arrive, vector<int> execute) {
    if (arrive.empty() || execute.empty() || arrive.size() != execute.size()) {
        return 0;
    }

    int next_job_id = 0;
    int wait_time = 0;
    int curr_time = 0;
    priority_queue<Job> jobq;
    while (!jobq.empty() || next_job_id < arrive.size()) {
        if (jobq.empty()) {
            jobq.push(Job(arrive[next_job_id], execute[next_job_id]));
            curr_time = arrive[next_job_id];
            ++next_job_id;
        } else {
            Job job = jobq.top();
            jobq.pop();

            wait_time += curr_time - job.arrive;
            curr_time += job.execute;
            while (next_job_id < arrive.size() && arrive[next_job_id] <= curr_time) {
                jobq.push(Job(arrive[next_job_id], execute[next_job_id]));
                ++next_job_id;
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

    std::cout << shortest_job_first(arrive, execute) << std::endl;;
    return 0;
}
