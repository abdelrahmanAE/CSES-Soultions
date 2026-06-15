// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <random>
#include <algorithm>
using namespace std;
#define ll long long
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
void solve() {
    ll n;
    cin >> n;
    bool first = true; 
 
    while (n != 1) {
        if (!first) {
            cout << " ";
        }
        cout << n;
        first = false;
 
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << " " << 1 << endl; 
}
 
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
 
    return 0;
}
