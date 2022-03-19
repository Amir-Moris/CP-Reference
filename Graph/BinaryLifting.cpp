   void buildTree() {
       //build the tree
   }
   void dfs(int node, int parent) {
       up[node][0] = parent;
       for (int i = 1; i < LOG; i++) {
           int kMinusOneAncestor = up[node][i - 1];
           up[node][i] = up[kMinusOneAncestor][i - 1];
       }
       for (auto child: adj[node])
           if (child != parent)
               dfs(child, node);
   }
