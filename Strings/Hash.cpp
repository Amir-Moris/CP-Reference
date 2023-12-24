const int N = 1e5 + 5, P1 = 31, P2 = 37, MOD = 1e9 + 7;

int add(int a, int b) {
    a = ((a % MOD) + MOD) % MOD, b = ((b % MOD) + MOD) % MOD;
    return (a + b) % MOD;
}

int mul(int a, int b) {
    a = ((a % MOD) + MOD) % MOD, b = ((b % MOD) + MOD) % MOD;
    return (a * 1LL * b) % MOD;
}

int fastpow(int b, int p) {
    if (!p) return 1;
    int ans = fastpow(mul(b, b), p / 2);
    return (p % 2 ? mul(ans, b) : ans);
}

int power1[N], power2[N];

void prePower() {
    power1[0] = power2[0] = 1;
    for (int i = 1; i < N; i++) {
        power1[i] = mul(P1, power1[i - 1]);
        power2[i] = mul(P2, power2[i - 1]);
    }
}

struct Hash {
    vector<pair<int, int>> prefixHash;

    Hash(string &s) {// Hash(i) = Hash(i - 1) * P + char_order
        prefixHash = vector<pair<int, int>>(s.size(), {0, 0}); // double Hashing
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a' + 1;
            prefixHash[i].first = add(mul(prefixHash[max(0, i - 1)].first, P1), cur);
            prefixHash[i].second = add(mul(prefixHash[max(0, i - 1)].second, P2), cur);
        }
    }

    pair<int, int> getHashVal() {
        return prefixHash.back();
    }

    pair<int, int> getHashRange(int l, int r) {// Hash(r) - (Hash(l - 1) * power[r - l + 1])
        if (l > r) return {0, 0};
        int First = add(prefixHash[r].first, -mul((l ? prefixHash[l - 1].first : 0), power1[r - l + 1]));
        int Second = add(prefixHash[r].second, -mul((l ? prefixHash[l - 1].second : 0), power2[r - l + 1]));
        return make_pair(First, Second);
    }

    pair<int, int> concat(pair<int, int> S1, pair<int, int> S2, int S2_size) {// S1 + S2
        S1.first = add(mul(S1.first, power1[S2_size]), S2.first);
        S1.second = add(mul(S1.second, power2[S2_size]), S2.second);
        return S1;
    }
};
