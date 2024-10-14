#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define forloop(i, a, b) for (int i = a; i < (b); i++)
#define put(x) cout << x << '\n'
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {}

int main()
{
    ios_base::sync_with_stdio(false);
#ifndef coderakhand_DEBUG
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
