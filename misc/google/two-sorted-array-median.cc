// Question: 找已经有序的2个数组的中位数。

double median(vector<int> a, vector<int> b) {
    int lena = a.size();
    int lenb = b.size();
    int count = lena + lenb;
    if (count % 2 == 1) {
        return find_kth(a, b, count/2+1);
    }
    return (find_kth(a, b, count/2) + find_kth(a, b, count/2+1)) * 1.0 / 2;
}

int find_kth(vector<int> a, vector<int> b, int k) {
    if (a.size() > b.size()) {
        return find_kth(b, a, k);
    }

    int lena = a.size(), lenb = b.size();
    if (lena == 0) {
        return b[k-1];
    }
    if (k == 1) {
        return min(a[0], b[0]);
    }

    int p1 = min(lena, k/2);
    int p2 = k - p1;
    if (a[p1-1] < b[p2-1]) {
        return find_kth(vector<int>(a.begin()+p1, a.end()), b, p2);
    } else if (a[p1-1] > b[p2-1]) {
        return find_kth(a, vector<int>(b.begin()+p2, b.end()), p1);
    } else {
        return a[p1-1];
    }
}
