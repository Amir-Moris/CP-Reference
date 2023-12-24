const int N = 2e5 + 5, MOD = 1e9 + 7;

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

int modinv(int b, int Mod) {
    return fastpow(b, MOD - 2);
}

// ************************** Combinatorics ************************** //
int fac[N];

void preFactorial() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = mul(i, fac[i - 1]);
    }
}

int nCr(int n, int r) {
    if (n < r) return 0;
    return mul(fac[n], fastpow(mul(fac[r], fac[n - r]), MOD - 2));
}

int nPr(int n, int r) {
    if (n < r) return 0;
    return mul(fac[n], fastpow(fac[n - r], MOD - 2));
}
