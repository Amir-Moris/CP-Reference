template<class T> struct segtree {
    int sz = 1;
    vector<T> sums;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        sums = vector<T> (2 * sz, 0);
    }

    void update(int pos, int val, int cur, int l, int r) {
        if(r - l == 1) {
            sums[cur] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(pos < mid) {
            update(pos, val, 2 * cur + 1, l, mid);
        } else {
            update(pos, val, 2 * cur + 2, mid, r);
        }
        sums[cur] = sums[2 * cur + 1] + sums[2 * cur + 2];
    }
    void update(int pos, int val) {
        update(pos, val, 0, 0, sz);
    }

    T getSum(int lx, int rx, int cur, int l, int r) {
        if(l >= rx || r <= lx) return 0;
        if(l >= lx && r <= rx) return sums[cur];
        int mid = (l + r) / 2;
        return getSum(lx, rx, 2 * cur + 1, l, mid) + getSum(lx, rx, 2 * cur + 2, mid, r);
    }
    T getSum(int l, int r) {
        return getSum(l, r, 0, 0, sz);
    }
};
