#include <bits/stdc++.h>
using namespace std;

#define all(v)                      v.begin(), v.end()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define fap(x)                      cout << "WTH: " << x << endl
#define ff                          first
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define pll                         pair<ll, ll>
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define timeTaken                   endd = clock(); cout << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
#define timeInit                    clock_t beginn = clock(), endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string, int>
#define umii                        unordered_map<int, int>
#define umis                        unordered_map<int, string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator

template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};

template<class T> ostream &operator<<(ostream &os, const pair<T, T> &a) { return os << a.ff << " " << a.ss; }
ll power(ll a, int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator+(const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator*(const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }

ll Set(ll N, int pos) { return N = N | (1LL << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(ll N, int pos){ return (bool) (N & (1LL << pos)); }

///=======================================template=======================================///

int main() {
    //FI;FO;
    //FastIO;//timeInit;

    int n;
    cin >> n;
    ll k;
    cin >> k;

    pii ara[n + 1], temp[n + 1];
    map<pii, int> arr;
    umii cn, last;
    int cntt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ara[i].ff;
        ara[i].ss = i;
        temp[i].ff = ara[i].ff;
    }

    sort(ara + 1, ara + n + 1);
    for (int i = 1; i <= n; i++) {
        arr[{ara[i].ff, ara[i].ss}] = i;
        last[ara[i].ff] = i;
        cn[ara[i].ff]++;
    }

    umii cnt;
    ll ans = 0, inv = 0;
    ordered_set os;

    for (int i = n; i > 1; i--) {
        os.insert(arr[{temp[i].ff, i}]);
        inv += os.order_of_key(last[temp[i].ff] - cn[temp[i].ff] + 1);
    }

    ordered_set os1;
    int from = 2;
    vb taken(n + 1, false);
    ll tt;
    for (int i = 1; i < n; i++) {
        ll invn = inv, ii = i;
        if (from > n)
            break;


        os1.insert(arr[{temp[i].ff, i}]);
        if (!taken[i]) {
            inv += (i - (os1.order_of_key(last[temp[i].ff] + 1)));
            inv += os.order_of_key(last[temp[i].ff] - cn[temp[i].ff] + 1);
        }

        if (inv <= k) {
            ans += n - from + 1;
        }

        if (from == i + 1 or inv > k) {
            ll t = inv;
            inv -= (i - (os1.order_of_key(last[temp[from].ff] + 1)));
            inv -= os.order_of_key(last[temp[from].ff] - cn[temp[from].ff] + 1);
            os.erase(arr[{temp[from].ff, from}]);
            from++;
            if (t > k)
                i--;
        }
        taken[ii] = true;
        //cout << inv <<" " << invn << " " << i << " " << ii << " " << from << " " << ans << endl;
    }

    cout << ans << endl;

    //timeTaken;
    return 0;
}
