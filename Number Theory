Extended Euclidean Algorithm (e-GCD)

void move1step(int& a, int& b, int q) {
    int next = a-q*b ;
    a = b;
    b = next;
}
int eGCD(int a, int b, int& x0, int& y0) { // a*x + b*y = r0
    int r0 = a, r1 = b;
    int x1, y1;
    x1 = y0 = 0;
    x0 = y1 = 1;
    while(r1!=0) {
        int q = r0/r1 ;
        move1step(x0, x1, q) ;
        move1step(y0, y1, q) ;
        move1step(r0, r1, q) ;
    }
    return r0 ;
}
_________________________________________________________________________
Fast Power

int fp(int b, int p) {
    if(p==0) return 1;
    long long ans = fp(1ll*b*b %mod,p/2) %mod ;
    if(p%2) return ans*b %mod;
    return ans%mod ;
}
_________________________________________________________________________
Combinatorics/nCr

const int N =1e5+5 ;
int fac[N] ;
void Factorial() {
    fac[0]=1 ;
    for(int i=1; i<N; i++)
        fac[i]=i*fac[i-1] %mod ;
}
long long comb(int n, int r) { // fp is fast powert
    return 1ll*fac[n] * fp(1ll*fac[r]*fac[n-r]%mod,mod-2) %mod ;
}
