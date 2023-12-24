int spf[N];

bool isPrime(int num) {
    return (num >= 2 && spf[num] == num);
}

void Sieve() { // num is prime if spf[num] = num, excluding {0, 1}
    for (int i = 0; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] != i) continue;
        for (int j = i * i; j < N; j += i)
            spf[j] = min(spf[j], i);
    }
}

void primeFactorization(int num) {
    vector<pair<int, int>> primes;
    while (num > 1) {
        int pf = spf[num], cnt = 0;
        while (num % pf == 0) {
            num /= pf, cnt++;
        }
    }
}
