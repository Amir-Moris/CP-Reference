struct suffix_array {
    int sz;
    string str;
    vector<int> p, c;
    suffix_array(string &str2) {
        str = str2 + '$';
        sz = str.size();
        p = c = vector<int>(sz);
        init();

        int k = 0;
        while((1 << k) < sz) {// k -> k + 1
            vector<pair<pair<int, int>, int>> neww(sz);
            for(int i=0; i<sz; i++) {
                neww[i] = {{c[i], c[(i + (1 << k)) % sz]}, i};
            }
            radix_sort(neww);
            for(int i=0; i<sz; i++) {
                p[i] = neww[i].second;
            }
            c[p[0]] = 0;
            for(int i=1; i<sz; i++) {
                c[p[i]] = c[p[i - 1]] + (neww[i].first != neww[i - 1].first);
            }
            k++;
        }
    }
    void init() {// k = 0
        vector<pair<char, int>> Base(sz);
        for(int i=0; i<sz; i++) {
            Base[i] = {str[i], i};
        }
        sort(Base.begin(), Base.end());
        for(int i=0; i<sz; i++) {
            p[i] = Base[i].second;
        }
        c[p[0]] = 0;
        for(int i=1; i<sz; i++) {
            c[p[i]] = c[p[i - 1]] + (Base[i].first != Base[i - 1].first);
        }
    }
    void radix_sort(vector<pair<pair<int, int>, int>> &v) {
        vector<pair<pair<int, int>, int>> sorted(sz);
        vector<int> cnt(sz), pos(sz);
        for(auto el : v) {// sort by second
            cnt[el.first.second]++;
        }
        for(int i = 0; i < sz; i++) {
            pos[i] = !i ? 0 : pos[i - 1] + cnt[i - 1];
        }
        for(auto el : v) {
            int idx = el.first.second;
            sorted[pos[idx]] = el;
            pos[idx]++;
        }
        cnt = pos = vector<int>(sz);
        for(auto el : sorted) {// sort by first
            cnt[el.first.second]++;
        }
        for(int i = 0; i < sz; i++) {
            pos[i] = !i ? 0 : pos[i - 1] + cnt[i - 1];
        }
        for(auto el : sorted) {
            int idx = el.first.first;
            v[pos[idx]] = el;
            pos[idx]++;
        }
    }
};
