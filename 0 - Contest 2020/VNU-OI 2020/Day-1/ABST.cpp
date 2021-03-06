/* Author: Bui Vi Quoc */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define FORD(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define sz(a) (int(a.size()))
#define BIT(a, i) (((a) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define turnON(a, i) ((a) | MASK(i))
#define turnOFF(a, i) ((a) & (~MASK(i)))
#define flipBit(n, bit) ((n) ^ (1LL << (bit)))
#define cntBit(n) __builtin_popcountll(n)
#define sqr(x) ((x)*(x))
#define endl '\n'
#define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    }
    return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    }
    return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

/*
(\_/)
( •_•)
/ >?? */

const int N = 300005;
int n, v[N], lf_child[N], rt_child[N];
int par[N];
stack <int> S;

void DFS(int i) {
    if (lf_child[i]) DFS(lf_child[i]);
    S.push(i);
    if (rt_child[i]) DFS(rt_child[i]);
}

#define FILE_IO
signed main(void) {
    FastIO;
    #ifdef FILE_IO
    freopen("ABST.INP","r",stdin);
    freopen("ABST.OUT","w",stdout);
    #endif
    
    cin >> n;
    FOR(i,1,n) {
        cin >> v[i] >> lf_child[i] >> rt_child[i];
        par[lf_child[i]] = i;
        par[rt_child[i]] = i;
    }

    FOR(i,1,n) if (!par[i]) DFS(i);
    
    priority_queue<int, vector<int>, greater<int> > heap;

    int res = 0;

    while (S.size()) {
        int i = S.top(); S.pop();
        if (!heap.empty() && v[i] > heap.top()) {
            res += v[i] - heap.top();
            heap.pop();
            heap.push(v[i]);
        }
        heap.push(v[i]);
    }

    cout << res;

    return 0;
}