// Coded  by Abdelrahman Elgammal
/*
بسم الله الرحمن الرحيم
وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ ثُمَّ يُجْزَاهُ الْجَزَاءَ الْأَوْفَىٰ
 */

#include <bits/stdc++.h>

using namespace std;

#define SHANBO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
// #define ll int
typedef long long ll;
#define int long long
#define double long double
#define Endl '\n';
const int N = 200001, mod = 1e9 + 7;

/*

                  ▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌
                  ▐                                                 ▌
                  ▐ ____    _   _      _      _   _   ____     ___  ▌
                  ▐/ ___|  | | | |    / \    | \ | | | __ )   / _ \ ▌
                  ▐\___ \  | |_| |   / _ \   |  \| | |  _ \  | | | |▌
                  ▐ ___) | |  _  |  / ___ \  | |\  | | |_) | | |_| |▌
                  ▐|____/  |_| |_| /_/   \_\ |_| \_| |____/   \___/ ▌
                  ▐                                                 ▌
                  ▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌


*/
///////////////////////////////////////////////// Combinatorics
// ll dp1[N][N];

// ll nCr_rec(ll n, ll r) { //O(1000,1000)
//     if(n < r) return 0;
//     if (n == r || r == 0) return 1;
//     ll &ret = dp1[n][r];
//     if (~ret) return ret;
//     return nCr_rec(n - 1, r - 1) + nCr_rec(n - 1, r);
// }

/////////////////////////////////////////////////Pascal Triangle Iterative

ll nCr_iter(ll n, ll r)
{ // O(1000, 1000)
    if (n < r)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(r + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= min(n, r); j++)
        {
            dp[i + 1][j] += dp[i][j];
            if (j < r)
                dp[i + 1][j + 1] += dp[i][j];
        }
    }
    return dp[n][r];
}

///////////////////////////////////////////////// nCr

int C1(int n, int k)
{
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i) // n! / (n - k)!
        res *= i;
    for (int i = 2; i <= k; ++i) // / k!
        res /= i;
    return res;
}

///////////////////////////////////////////////// nCr

int C2(int n, int k)
{ // O(1e6)
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

/////////////////////////////////////////////////nCr with Modulo

ll fact[N + 1];
ll inv_fact[N + 1];

ll modPow(ll x, ll n, ll mod)
{
    x %= mod;
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

/////////////////////////////////////////////////Precompute Factorials

void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % p;
    }
}

/////////////////////////////////////////////////Precompute Inverse Factorials

void inv_factorial(ll p)
{
    inv_fact[N] = modPow(fact[N], p - 2, p);
    for (int i = N; i >= 1; i--)
    {
        inv_fact[i - 1] = inv_fact[i] * i % p;
    }
}

ll NPR(ll n, ll r, ll p)
{
    return fact[n] * inv_fact[n - r] % p;
}

ll NCR(ll n, ll r, ll p)
{
    return fact[n] * inv_fact[r] % p * inv_fact[n - r] % p;
}

void pre_process(ll p)
{
    factorial(p);
    inv_factorial(p);
}

// Number Theory Algorithms

//  1. Check if a number is prime
// Time: O(√n)
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int nextPrime(int n)
{
    int p = n + 1;
    while (!isPrime(p))
        p++;
    return p;
}

/*

2. Primality test for large numbers (Miller-Rabin)
Time: ~O(log³n) (for n ≤ 10¹⁸)
*/

ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool millerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1)
    {
        x = mulmod(x, x, n);
        d *= 2;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

bool isPrimeMR(ll n, int k = 5)
{
    if (n <= 4)
        return n == 2 || n == 3;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;
    return true;
}

/*

 3. Sieve of Eratosthenes
Time: O(n log log n)
*/
bool isPrimee[N];

void sieve()
{
    fill(isPrimee, isPrimee + N, true);
    isPrimee[0] = isPrimee[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (isPrimee[i])
            for (int j = i * i; j < N; j += i)
                isPrimee[j] = false;
    }
}

//-------------------END----------------------------
/*
 4. Finding all divisors of n
Time: O(√n)
*/
vector<int> getDivisors(int n)
{
    vector<int> d;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }
    return d;
}

//-------------------END----------------------------

// GCD and LCD
/*
 5. GCD
Time: O(log min(a, b))
*/
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

/*
6. LCM using GCD
Time: O(log min(a, b))
*/

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    int n;
    cin >> n;
    cout << power(2, n, mod);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    SHANBO
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}