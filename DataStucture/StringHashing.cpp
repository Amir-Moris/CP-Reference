#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5, p1=31, p2=37, mod=1e9+7 ;
int add(int a, int b) {
    a = ((a%mod) + mod) %mod, b = ((b%mod) + mod) %mod ;
    return (a + b) %mod ;
}
int mul(int a, int b) {
    a = ((a%mod) + mod) %mod, b = ((b%mod) + mod) %mod ;
    return (a * 1LL * b) %mod ;
}
int fp(int b, int p) {
    if(!p) return 1;
    ll ans = fp(mul(b,b), p/2) ;
    if(p%2) return mul(ans,b) ;
    return ans%mod ;
}
int modinv(int b,int mod) {
    return fp(b,mod-2) ;
}
int power1[N], inv1[N], power2[N], inv2[N] ;
void prePow() {
    power1[0] = inv1[0] = 1;
    power2[0] = inv2[0] = 1;
    int inverse1 = modinv(p1,mod-2), inverse2 = modinv(p2,mod-2) ;
    for(int i=1; i<N; i++) {
        power1[i] = mul(p1,power1[i-1]) ;
        inv1[i] = mul(inverse1,inv1[i-1]) ;

        power2[i] = mul(p2,power2[i-1]) ;
        inv2[i] = mul(inverse2,inv2[i-1]) ;
    }
}
struct Hash {
    vector<pair<int,int>> prefixHash ;

    Hash(string &s) {
        prefixHash = vector<pair<int, int>> (s.size()); // double Hashing
        for(int i=0; i<s.size(); i++) {
            int cur = i - 'a' ;

            int f = mul(cur + 1, power1[i]) ;
            int s = mul(cur + 1, power2[i]) ;
            f = add(f, prefixHash[max(0,i - 1)].first) ;
            s = add(s, prefixHash[max(0,i - 1)].second) ;
            prefixHash[i] = {f,s} ;
        }
    }
  
    pair<int,int> getHashVal() {
        return prefixHash.back() ;
    }
  
    pair<int,int> getHashRange(int l, int r) {
        int f = add(prefixHash[r].first, -(l ? prefixHash[l - 1].first : 0)) ;
        int s = add(prefixHash[r].second, -(l ? prefixHash[l - 1].second : 0)) ;
        f = mul(f,inv1[l]), s = mul(s,inv1[l]) ;

        return make_pair(f,s) ;
    }
};
int main() {
    
    prePow() ;

}
