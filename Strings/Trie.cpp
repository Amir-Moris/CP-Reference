struct Trie {
    struct Node {
        int freq = 0;
        Node *ptr[27];

        Node() {
            for (int i = 0; i < 26; i++) {
                ptr[i] = NULL;
            }
        }
    } *root = new Node();

    Trie() {}

    void insert(string &str) {
        Node *cur = root;
        for (auto &i: str) {
            int ch = i - 'a';
            if (cur->ptr[ch] == NULL)
                cur->ptr[ch] = new Node();

            cur = cur->ptr[ch];
            cur->freq++;
        }
    }

    int search(string &str) {
        Node *cur = root;
        for (auto &i: str) {
            int ch = i - 'a';
            if (cur->ptr[ch] == NULL)
                return 0;

            cur = cur->ptr[ch];
        }
        return cur->freq;
    }
};
