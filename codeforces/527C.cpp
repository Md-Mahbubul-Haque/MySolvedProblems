#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
*/

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(ll N,int pos){  return (bool) (N&(1LL<<pos));}

///=======================================template=======================================///

int main()
{
    //FI;//FO;
    FastIO;

    int w,h,n;
    cin >> w >> h >> n;
    set<int> H, V;
    multiset<int> HH,VV;
    H.insert(0);
    H.insert(h);
    V.insert(0);
    V.insert(w);

    HH.insert(h);
    VV.insert(w);
    while( n-- > 0){
        char ch; cin >> ch;

        if(ch == 'H'){
            int y; cin >> y;
            auto it = H.lower_bound(y);
            it--;
            int low=*it;
            it = H.upper_bound(y);
            int high=*it;
            it = HH.find(high-low);
            HH.erase(it);
            HH.insert(y-low);
            HH.insert(high-y);
            H.insert(y);
            ll v = *(--HH.end());
            ll hh = *(--VV.end());
            cout<< hh * v <<endl;
        }
        else {
            int x; cin >> x;
            auto it = V.lower_bound(x);
            it--;
            int low=*it;
            it = V.upper_bound(x);
            int high = *it;
            it = VV.find(high - low);
            VV.erase(it);
            VV.insert(x - low);
            VV.insert(high - x);
            V.insert(x);
            ll vv = *(--VV.end());
            ll hh = *(--HH.end());
            cout << hh * vv <<endl;
        }
    }

    //timeTaken;
    return 0;
}
