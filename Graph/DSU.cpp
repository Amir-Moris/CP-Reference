struct DSU {
    vector<int> parent, Rank;
    int forests = 0;
    DSU(int sz) {
        parent = Rank = vector<int> (sz + 5);
        forests = 0;
    }
    void make_set(int a) {
        parent[a] = a;
        Rank[a] = 1;
        forests++;
    }
    int find_set(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }
    bool connect(int a, int b) {
        a = find_set(a), b = find_set(b);
        if(a != b) {
            if(Rank[a] > Rank[b]) swap(a, b);
            parent[a] = b;
            if(Rank[a] == Rank[b]) Rank[b]++;
            forests--;
        }
        return a != b;
    }
};
