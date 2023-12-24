ll SumOfArithmeticSequence(ll n, ll a, ll d) {
    return (n * (2 * a + (n - 1) * d)) / 2;
}

ll SumOfGeometricSequence(ll n, ll a, ll r) {
    return (a * ((ll)pow(r, n) - 1)) / (r - 1);
}
