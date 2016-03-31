// Question: Reverse word in a sentence.

#include "headers.h"

// void reverse(char* s, int start, int end) {
//     int i = start;
//     int j = end-1;
//     while (i < j) {
//         swap(s[i], s[j]);
//         ++i;
//         --j;
//     }
// }

void solve(char* s, int len) {
    int i = 0;
    while (i < len) {
        int j = i;
        while (j < len && s[j] != ' ') {
            ++j;
        }
        reverse(s+i, s+j);
        i = j+1;
    }
    reverse(s, s+len);
}

int main(int argc, char** argv) {
    char s[] = "i love you";
    solve(s, 10);
    cout << s << endl;
}
