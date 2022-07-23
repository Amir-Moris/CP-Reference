template<class T> struct segtree {
    int sz = 1;
    vector<T> sums;
    void init(int n) {
        int tmp = 1;
        sz = n;
        while(tmp < n) tmp *= 2;
        sums = vector<T> (2 * tmp, 0);
    }
    void update(int cur, int l, int r, int pos, int value) {
        if(l == r) {
            sums[cur] = value;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(2 * cur + 1, l, mid, pos, value);
        else
            update(2 * cur + 2, mid + 1, r, pos, value);

        sums[cur] = sums[2 * cur + 1] + sums[2 * cur + 2];
    }
    void update(int pos, int value) {
        update(0, 0, sz, pos, value);
    }

    T getSum(int cur, int l, int r, int lx, int rx) {
        if(l > rx || r < lx) return 0;
        if(l >= lx && r <= rx) return sums[cur];
        int mid = (l + r) / 2;
        return getSum(2 * cur + 1, l, mid, lx, rx)
               + getSum(2 * cur + 2, mid + 1, r, lx, rx);
    }
    T getSum(int lx, int rx) {
        return getSum(0, 0, sz, lx, rx);
    }
};
