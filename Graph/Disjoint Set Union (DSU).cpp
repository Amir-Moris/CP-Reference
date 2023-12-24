struct DSU {
    vector<int> par, Rank;
    int forests = 0;

    DSU(int sz) {
        par = Rank = vector<int>(sz + 5);
        forests = 0;
    }

    void make_set(int u) {
        par[u] = u;
        Rank[u] = 1;
        forests++;
    }

    int find_set(int u) {
        if (par[u] == u) return u;
        return par[u] = find_set(par[u]);
    }

    void union_set(int u, int v) {
        u = find_set(u), v = find_set(v);
        if (Rank[u] < Rank[v]) swap(u, v);
        par[v] = u;
        Rank[u] += (Rank[u] == Rank[v]);
        forests--;
    }
};
