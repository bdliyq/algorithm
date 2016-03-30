// Question: Reverse word in a sentence.

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
    reverse(s+i, s+j);
}
