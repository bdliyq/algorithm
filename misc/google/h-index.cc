// Question: H-index.

int solve(vector<int> citations) {
    int len = citations.size();
    if (len == 0) {
        return len;
    }

    sort(citations.begin(), citations.end());
    for (int i = 0; i < len; ++i) {
        if (citations[i] >= len-i) {
            return len-i;
        }
    }
    return 0;
}

int solve(vector<int> citations) {
    int len = citations.size();
    vector<int> v(len+1, 0);
    for (auto c : citations) {
        if (c > len) {
            ++v[len];
            continue;
        }
        ++v[c];
    }

    int count = 0;
    for (int i = len; i >= 0; --i) {
        count += v[i];
        if (count >= i) {
            return i;
        }
    }
    return 0;
}

// citations has been sorted.
int solve(vector<int> citations) {
    int len = citations.size();
    int l = 0, r = len-1;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (citations[m] < len-m) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return len-l;
}
