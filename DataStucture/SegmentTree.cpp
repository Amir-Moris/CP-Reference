template<class T> struct segtree {
    int sz = 1;
    vector<T> sums;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        sums = vector<T> (2 * sz, 0);
    }
    
    void setValue(int i, int v, int idx, int lx, int rx) {
        if(rx - lx == 1) {
            sums[idx] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if(i < m) {
            setValue(i, v, 2 * idx + 1, mid, rx);
        } else {
            setValue(i, v, 2 * idx + 2, lx, mid);
        }
        sums[idx] = sums[2 * idx + 1] + sums[2 * idx + 2];
    }
    void setValue(int i, int v) {
        setValue(i, v, 0, 0, sz);
    }

    T sum(int l, int r, int idx, int lx, int rx) {
        if(lx >= r || rx <= l) return 0;
        if(lx >= l && rx <= r) return sums[idx];
        int mid = (lx + rx) / 2;
        return sum(l, r, 2 * idx + 1, lx, mid) + sum(l, r, 2 * idx + 2, mid, rx);
    }
    T sum(int l, int r) {
        return sum(l, r, 0, 0, sz);
    }
};
