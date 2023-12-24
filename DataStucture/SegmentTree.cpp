struct segmantTree {
    int sz, lazy = -1;
    vector<int> ans, vec;

    segmantTree(int sz, vector<int> &v) : vec(v), sz(sz) {
        ans = vector<int>(4 * sz + 5, 0);
        Build(1, 1, sz);
    }

    int Merge(int left, int right) {
        // code here
        return max(left, right);
    }

    // Non-Commutative
    void apply_operation(int &child, int &parent) {
        // code here
        if (parent != lazy) child = parent;
    }

    void propagate(int cur, int l, int r) {
        if (l == r) return;
        apply_operation(ans[2 * cur], ans[cur]);
        apply_operation(ans[2 * cur + 1], ans[cur]);
        ans[cur] = lazy;
    }

    void tupdateRange(int cur, int tl, int tr, int l, int r, int v) {
        if (tl > r || tr < l) return;
        propagate(cur, tl, tr);
        if (tl >= l && tr <= r) return void(ans[cur] = v);

        int mid = (tl + tr) / 2;
        tupdateRange(2 * cur, tl, mid, l, r, v);
        tupdateRange(2 * cur + 1, mid + 1, tr, l, r, v);
    }

    void updateRange(int l, int r, int v) {
        tupdateRange(1, 1, 1, l, r, v);
    }

    // Commutative
    void Build(int cur, int tl, int tr) {
        if (tl == tr) {
            ans[cur] = vec[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        Build(2 * cur, tl, mid);
        Build(2 * cur + 1, mid + 1, tr);
        ans[cur] = Merge(ans[2 * cur], ans[2 * cur + 1]);
    }

    void tupdate(int cur, int tl, int tr, int pos, int val) {
        if (tl == tr) return void(ans[cur] = val);

        int mid = (tl + tr) / 2;
        if (pos <= mid) tupdate(2 * cur, tl, mid, pos, val);
        else tupdate(2 * cur + 1, mid + 1, tr, pos, val);
        ans[cur] = Merge(ans[2 * cur], ans[2 * cur + 1]);
    }

    int tsolve(int cur, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return INT_MIN;
        if (tl >= l && tr <= r) return ans[cur];

        int mid = (tl + tr) / 2;
        int left = tsolve(2 * cur, tl, mid, l, r);
        int right = tsolve(2 * cur + 1, mid + 1, tr, l, r);
        return Merge(left, right);
    }

    int solve(int l, int r) {
        // code here
        return tsolve(1, 1, sz, l, r);
    }

    void update(int pos, int val) {
        // code here
        tupdate(1, 1, sz, pos, val);
    }
};
