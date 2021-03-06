#include <bits/stdc++.h>
using namespace std;

#define all(v)                      v.begin(), v.end()
#define Chrono                      chrono::steady_clock::now().time_since_epoch().count()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-15
#define eb                          emplace_back
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define ff                          first
#define gt(i, x)                    get<i>(x)
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define mt                          make_tuple
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define iii                         pair<int, pii>
#define iiii                        pair<pii, pii>
#define pll                         pair<ll, ll>
#define present(c, x)               ((c).find(x) != (c).end())
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define tii                         tuple<int, int>
#define tiii                        tuple<int, int, int>
#define tiiii                       tuple<int, int, int, int>
#define timeTaken                   endd = clock(); cerr << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
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
#define bug(...)                    cerr << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
template<class T> void _Print(T &&x) { cerr << x << ")" << endl; }
template<class T, class ...S> void _Print(T &&x, S &&...y) { cerr << x << ", "; _Print(y...); }


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

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }

///=======================================template=======================================///

int main() {
    //FI;FO;
    FastIO; //timeInit;

    int n, m;
    while (cin >> n >> m and (n | m)) {
        int mat[n + 1][m + 1];
        mem(mat, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                if (x) {
                    mat[i + 1][j] = mat[i][j] = mat[i][j + 1] = mat[i + 1][j + 1] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
            mat[i][0] = 1;
        for (int i = 0; i < m; i++)
            mat[0][i] = 1;


        int dist[n][m][4];
        for (auto &x : dist) {
            for (auto &y : x)
                for (auto &z : y)
                    z = INT_MAX;
        }

        int sx, sy, ex, ey, d = 0;
        cin >> sx >> sy >> ex >> ey;
        string dir;
        cin >> dir;
        if (dir == "south")
            d = 2;
        else if (dir == "west")
            d = 1;
        else if (dir == "east")
            d = 3;
        else d = 0;

        queue<tiiii> qu;

        if (mat[sx][sy]== 0) {
            qu.push({0, sx, sy, d});
            dist[sx][sy][d] = 0;
        }

        int par[n][m][4];
        mem(par, -1);

        while (!qu.empty()) {
            auto x = qu.front();
            qu.pop();

            int ds = gt(0, x), xx = gt(1, x), xy = gt(2, x), di = gt(3, x);

            if (di == 0) {
                if (dist[xx][xy][1] == INT_MAX) {
                    dist[xx][xy][1] = ds + 1;
                    qu.push({ds + 1, xx, xy, 1});
                }
                if (dist[xx][xy][3] == INT_MAX) {
                    dist[xx][xy][3] = ds + 1;
                    qu.push({ds + 1, xx, xy, 3});
                }
                for (int i = 1; i <= 3; i++) {
                    if (xx - i > 0 and mat[xx - i][xy] == 0 and dist[xx - i][xy][di] == INT_MAX) {
                        dist[xx - i][xy][di] = ds + 1;
                        qu.push({ds + 1, xx - i, xy, di});
                    }
                    else if (mat[xx - i][xy] == 1)
                        break;
                }
            }
            else if (di == 1) {
                if (dist[xx][xy][0] == INT_MAX) {
                    dist[xx][xy][0] = ds + 1;
                    qu.push({ds + 1, xx, xy, 0});
                }
                if (dist[xx][xy][2] == INT_MAX) {
                    dist[xx][xy][2] = ds + 1;
                    qu.push({ds + 1, xx, xy, 2});
                }

                for (int i = 1; i <= 3; i++) {
                    if (xy - i > 0 and mat[xx][xy - i] == 0 and dist[xx][xy - i][di] == INT_MAX) {
                        dist[xx][xy - i][di] = ds + 1;
                        qu.push({ds + 1, xx, xy - i, di});
                    }
                    else if (mat[xx][xy - i] == 1)
                        break;
                }
            }
            else if (di == 2) {
                if (dist[xx][xy][1] == INT_MAX) {
                    dist[xx][xy][1] = ds + 1;
                    qu.push({ds + 1, xx, xy, 1});
                }
                if (dist[xx][xy][3] == INT_MAX) {
                    dist[xx][xy][3] = ds + 1;
                    qu.push({ds + 1, xx, xy, 3});
                }

                for (int i = 1; i <= 3; i++) {
                    if (xx + i < n and mat[xx + i][xy] == 0 and dist[xx + i][xy][di] == INT_MAX) {
                        dist[xx + i][xy][di] = ds + 1;
                        qu.push({ds + 1, xx + i, xy, di});
                    }
                    else if (mat[xx + i][xy] == 1)
                        break;
                }


            }
            else {
                if (dist[xx][xy][0] == INT_MAX) {
                    dist[xx][xy][0] = ds + 1;
                    qu.push({ds + 1, xx, xy, 0});
                }
                if (dist[xx][xy][2] == INT_MAX) {
                    dist[xx][xy][2] = ds + 1;
                    qu.push({ds + 1, xx, xy, 2});
                }
                for (int i = 1; i <= 3; i++) {
                    if (xy + i < m and mat[xx][xy + i] == 0 and dist[xx][xy + i][di] == INT_MAX) {
                        dist[xx][xy + i][di] = ds + 1;
                        qu.push({ds + 1, xx, xy + i, di});
                    }
                    else if (mat[xx][xy + i] == 1)
                        break;
                }

            }

        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            ans = min(dist[ex][ey][i], ans);
        }
        if (ans == INT_MAX)
            ans = -1;
        cout << ans << endl;
    }

    //timeTaken;
    return 0;
}
