const int N = 1e5+5, P1 = 31, P2 = 37, MOD = 1e9+7 ;
int add(int a, int b) {
    a = ((a % MOD) + MOD) % MOD, b = ((b % MOD) + MOD) % MOD ;
    return (a + b) %MOD ;
}
int mul(int a, int b) {
    a = ((a % MOD) + MOD) % MOD, b = ((b % MOD) + MOD) % MOD ;
    return (a * 1LL * b) %MOD ;
}
int fp(int b, int p) {
    if(!p) return 1;
    int ans = fp(b * 1LL * b %MOD, p/2) %MOD ;
    if(p%2) return ans * 1LL * b %MOD;
    return ans%MOD;
}
int MODinv(int b, int MOD) {
    return fp(b, MOD - 2) ;
}
int power1[N], inv1[N], power2[N], inv2[N] ;
void PrePower() {
    power1[0] = inv1[0] = power2[0] = inv2[0] = 1;
    int MODInverse1 = MODinv(P1, MOD);
    int MODInverse2 = MODinv(P2, MOD);
    for(int i=1; i<N; i++) {
        power1[i] = mul(P1, power1[i - 1]) ;
        power2[i] = mul(P2, power2[i - 1]) ;
        inv1[i] = mul(MODInverse1, inv1[i - 1]) ;
        inv2[i] = mul(MODInverse2, inv2[i - 1]) ;
    }
}
struct Hash {
    vector<pair<int,int>> prefixHash ;

    Hash(string &s) {
        prefixHash = vector<pair<int, int>> (s.size()); // double Hashing
        for(int i=0; i<s.size(); i++) {
            int cur = s[i] - 'a' + 1;

            int First = mul(cur, power1[i]) ;
            int Second = mul(cur, power2[i]) ;
            First = add(First, prefixHash[max(0, i - 1)].first) ;
            Second = add(Second, prefixHash[max(0, i - 1)].second) ;
            prefixHash[i] = make_pair(First,Second) ;
        }
    }

    pair<int,int> getHashVal() {
        return prefixHash.back() ;
    }

    pair<int,int> getHashRange(int l, int r) {
        int First = add(prefixHash[r].first, -(l ? prefixHash[l - 1].first : 0)) ;
        int Second = add(prefixHash[r].second, -(l ? prefixHash[l - 1].second : 0)) ;
        First = mul(First,inv1[l]), Second = mul(Second,inv2[l]) ;

        return make_pair(First,Second) ;
    }
};
int main() {
    PrePower();

}
