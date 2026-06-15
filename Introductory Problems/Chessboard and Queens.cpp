 // Coded  by Abdelrahman Elgammal
/*
بسم الله الرحمن الرحيم
وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ ثُمَّ يُجْزَاهُ الْجَزَاءَ الْأَوْفَىٰ
 */

#include <bits/stdc++.h>

using namespace std;

#define SHANBO  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
vector<string> grid;
bool col[9];
bool diag1[17];
bool diag2[17];

int fun(int row)
{

    if (row == 8)
        return 1;

    int ans = 0;
    for (int c = 0; c < 8; c++)
    {
        if (grid[row][c] == '*' || col[c] || diag1[row + c] || diag2[row - c + 8])
            continue;

        grid[row][c] = 'Q';

        col[c] = diag1[row + c] = diag2[row - c + 8] = 1;

        ans += fun(row + 1);

        grid[row][c] = '.';
        col[c] = diag1[row + c] = diag2[row - c + 8] = 0;
    }

    return ans;
}
void solve() {
    grid.resize(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }

    cout << fun(0) << Endl
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    SHANBO
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
