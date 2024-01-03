#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")

#define fre freopen("input.in", "r", stdin); freopen("output.out", "w", stdout);
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ld long double

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = acos(-1);
const int N = 1e5 + 5, MOD = 1e9 + 7;

int rand(int l, int r) {
    // to get any random number use rng()
    return uniform_int_distribution<int>(l, r)(rng);
}

void doWork() {

}

int main() {
    IO
    int Tc = 1;
    cin >> Tc;
    for (int i = 1; i <= Tc; i++) {
        //  cout << "Case #" << i << ": ";
        doWork();
    }
}
