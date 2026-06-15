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
const int N = 1e7 + 5;

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

void solve()
{
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b))
        cout << "YES" << Endl else cout << "NO" << Endl
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    SHANBO
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}