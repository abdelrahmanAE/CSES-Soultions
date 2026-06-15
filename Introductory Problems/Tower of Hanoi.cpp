// Coded  by Abdelrahman Elgammal
/*
بسم الله الرحمن الرحيم
وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ ثُمَّ يُجْزَاهُ الْجَزَاءَ الْأَوْفَىٰ
 */


#include <limits>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define SHANBO  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define ll int
typedef long long ll;
#define int long long
#define double long double

#define Endl '\n';
#define output(v) for(auto&it:v){cout<<it<<" ";}cout<<Endl
#define atb3(ans)  cout<<ans<<Endl;
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) (__builtin_ctzll(x))
#define bit_count(x) (__builtin_popcountll(x))
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template<typename T>
// using ordered_set = tree<T, null_type, std::greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T, null_type, std::greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool TC = false;
const long long MOD = 1e9 + 7;
const int MAX_A = 1e5 + 1;
const int MAX_TEMP = 200000;
const int N = 1e7 + 5;
const int M = 1e3 + 5;
// const int N = 2e5 + 10;
const int LG = 31;
const int oo = 1e18 + 5;
const int inf = 1e9 + 7;;


const int MAX_LIMIT = 1e18;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
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
void sol(int n,int l,int m,int r) {
    if (n == 1) {
        cout << l << " " << r << Endl
        return;
    }
    sol(n - 1, l, r, m);
    cout << l << " " << r << Endl
    sol(n - 1, m, l, r);
}

void solve() {
    int n; cin >> n;
    cout << (1 << n) - 1 << Endl
    sol(n, 1, 2, 3);
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
