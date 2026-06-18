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

void solve() { // UP solved version
    int n;
    cin >> n; // Read the total number of cubes

    // multiset to store only the top values of the currently active towers.
    // It keeps the tower tops sorted automatically, allowing O(log N) searches.
    multiset<int> ms;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // Read the size of the current cube

        // Find the first tower whose top is strictly greater than the current cube 'x'
        auto it = ms.upper_bound(x);

        if (it == ms.end()) {
            // Case 1: No existing tower has a top larger than 'x'.
            // We are forced to start a new tower with 'x' as its base/top.
            ms.insert(x);
        }
        else {
            // Case 2: A suitable tower was found (its current top is pointed to by 'it').
            // We greedily place 'x' on top of this tower.
            ms.erase(it);   // Remove the old top from the multiset (it's now covered)
            ms.insert(x);  // Insert 'x' as the new top of this existing tower
        }
    }

    // The total number of active towers is exactly the size of the multiset
    cout << ms.size();
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    SHANBO
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
