const int N = 1e5 + 5;
vector<vector<int>> adj, up;
int LOG, depth[N];

void DFS(int node, int parent) {
    up[node][0] = parent;
    depth[node] = depth[parent] + 1;

    for (int bit = 1; bit < LOG; bit++) {
        int prev = up[node][bit - 1];
        up[node][bit] = up[prev][bit - 1];
    }

    for (auto child: adj[node]) {
        if (child != parent) {
            DFS(child, node);
        }
    }

}

bool mnwr(int mask, int bit) {
    return (mask >> bit) & 1;
}

int getKthAncestor(int node, int k) {
    if (k > depth[node]) return 0;

    for (int j = LOG - 1; j >= 0; j--) {
        if (mnwr(k, j)) {
            node = up[node][j];
        }
    }
    return node;
}

void zpt(int sz) {
    LOG = log2(sz) + 1;
    adj = vector<vector<int>>(sz + 5, vector<int>());
    up = vector<vector<int>>(sz + 5, vector<int>(LOG + 5));
}
