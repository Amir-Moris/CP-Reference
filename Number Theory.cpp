// ** Extended Euclidean Algorithm (e-GCD) ** //

void move1step(int& a, int& b, int q) {
    int next = a - q * b ;
    a = b;
    b = next;
}
int eGCD(int a, int b, int& x0, int& y0) { // a*x + b*y = g
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
    return r0;
}
// ***************************************************************************************** //
// ** Fast Power ** //

int fp(int b, int p) {
    if(!p) return 1;
    int ans = fp(b * 1LL * b %MOD, p/2) %MOD ;
    if(p%2) return ans * 1LL * b %MOD;
    return ans%MOD;
}
// ***************************************************************************************** //
// ** Modular Inverse ** //

int modinv(int b, int Mod) { // mod must be prime
    return fp(b, Mod - 2) ;
}
// ***************************************************************************************** //
// ** Combinatorics/nCr ** //

const int N = 1e5+5, MOD = 1e9+7 ;
int fac[N] ;
void PreFactorial() {
    fac[0] = 1;
    for(int i=1; i<N; i++)
        fac[i] = i * 1LL * fac[i - 1] %MOD ;
}
int comb(int n, int r) {
    if(n < r) return 0;
    return fac[n] * 1LL * fp(fac[r] * 1LL * fac[n - r] %MOD, MOD - 2) %MOD ;
}
// ***************************************************************************************** //

