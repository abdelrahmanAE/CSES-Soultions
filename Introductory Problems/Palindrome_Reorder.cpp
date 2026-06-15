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
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2)
            odd++;
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION";
        return;
    }
    string left = "", mid = "";
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2)
            mid = string(1, char('A' + i));
        left += string(freq[i] / 2, char('A' + i));
    }
    string right = left;
    reverse(right.begin(), right.end());
    cout << left + mid + right;
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
    while (t--)
    {
        solve();
    }
    return 0;
}