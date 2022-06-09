struct DSU {
    vector<int> par, Rank;
    int forests = 0;
    DSU(int sz) {
        par = Rank = vector<int> (sz + 5);
        forests = 0;
    }

    void make_set(int& x) {
        par[x] = x;
        Rank[x] = 1;
        forests++;
    }
    
    int find_set(int x) {
        if(par[x] == x) return x;
        return par[x] = find_set(par[x]);
    }
    
    void connect(int x, int y) {
        x = find_set(x), y = find_set(y);
        if(Rank[x] < Rank[y]) swap(x, y);
        par[y] = x;
        Rank[x] += (Rank[x] == Rank[y]);
        forests--;
    }
};
