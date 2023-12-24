const int N = 1e5 + 5, SQRT = 320;

struct query {
    int l, r, idx, blockID;

    query() {}

    query(int ql, int qr, int qidx) : l(ql), r(qr), idx(qidx) {
        blockID = ql / SQRT;
    }

    bool operator<(const query &q) {
        if (blockID != q.blockID) return blockID < q.blockID;
        return r < q.r;
    }
} qu[N];

int result, ans[N];

void add(int i) {

}

void Remove(int i) {

}

void solvequeries(int q) {
    sort(qu, qu + q);

    int curL = 1, curR = 0;
    for (int j = 0; j < q; j++) {
        int L = qu[j].l;
        int R = qu[j].r;
        int I = qu[j].idx;

        while (curL < L) Remove(curL++);
        while (curL > L) add(--curL);

        while (curR < R) add(++curR);
        while (curR > R) Remove(curR--);

        ans[I] = result;
    }
}
