const int N = 1e5 + 5;
vector<vector<int>> adj, up;
int LOG, timer, tin[N], tout[N];

void DFS(int node, int parent) {
    tin[node] = timer++;
    up[node][0] = parent;

    for (int bit = 1; bit < LOG; bit++) {
        int prev = up[node][bit - 1];
        up[node][bit] = up[prev][bit - 1];
    }
    for (auto child: adj[node]) {
        if (child != parent) {
            DFS(child, node);
        }
    }
    tout[node] = timer++;
}

bool isAncestor(int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int LCA(int x, int y) {
    if (isAncestor(x, y)) return x;
    if (isAncestor(y, x)) return y;
    for (int k = LOG - 1; k >= 0; k--) {
        if (!isAncestor(up[x][k], y)) {
            x = up[x][k];
        }
    }
    return up[x][0];
}

void zpt(int sz) {
    timer = 0;
    LOG = log2(sz) + 1;
    adj = vector<vector<int>>(sz + 5, vector<int>());
    up = vector<vector<int>>(sz + 5, vector<int>(LOG + 5));
}

void BuildTree() {

}
