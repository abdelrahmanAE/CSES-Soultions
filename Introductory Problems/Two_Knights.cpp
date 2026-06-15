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
const int N = 2000007, mod = 1000000007;

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
ll fact[N], inv[N];

ll bigmod(ll x, int p)
{
    if (p == 0)
        return 1;
    ll mul = bigmod(x, p / 2);
    mul %= mod;
    if (p % 2 == 0)
        return (mul * mul) % mod;
    else
        return ((mul * mul) % mod * x) % mod;
}

void calcFact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[N - 1] = bigmod(fact[N - 1], mod - 2);
    for (ll i = N - 2; i >= 0; i--)
    {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

ll nCr(int a, int b)
{
    return ((fact[a] * inv[b]) % mod * inv[a - b]) % mod;
}

ll nC2(ll n)
{
    return n * (n - 1) / 2;
}

void solve()
{
    int num;
    cin >> num;
    for (ll n = 1; n <= num; n++)
    {
        cout << nC2(n * n) - 4 * (n - 1) * (n - 2) << endl;
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    SHANBO
    int t = 1;
    // cin >> t;
    calcFact();
    while (t--)
    {
        solve();
    }
    return 0;
}