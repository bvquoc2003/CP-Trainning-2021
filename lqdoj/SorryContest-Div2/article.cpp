// http://lqdoj.edu.vn/problem/article
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

string res = "a";

signed main(void) {
    FastIO;
    char s;
    cin >> s;
    if (s == 'e' || s == 'u' || s == 'o' || s == 'a' || s == 'i') res = "an";
    cout << res;
    return 0;
}