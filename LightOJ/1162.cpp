#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define siz(x) (int)x.size()
#define sfi(x) scanf("%d",&x);
#define sfii(x,y) scanf("%d%d",&x,&y)
#define sfiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pii pair<int,int>
#define pib pair<int,bool>
#define PQ priority_queue
#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i].ff<<" "; cout<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

int n;
vvii adjLst;
vii parent,parent1;
vi level;
pair<int,pii> table[100005][17];

void dfs(int from,int u,int dep,int cost,int mcost){
    parent[u]=mp(from,cost);
    parent1[u]=mp(from,mcost);
    level[u]=dep;
    fof(i,0,siz(adjLst[u])){
        pii v=adjLst[u][i];

        if(v.ff!=from){
            dfs(u,v.ff,dep+1,v.ss,v.ss);
        }
    }
}

void init_lca(){
    fof(i,0,100005) fof(j,0,17) table[i][j]=mp(-1,mp(INT_MAX,0));

    fof(i,0,n) table[i][0]=mp(parent[i].ff,mp(parent[i].ss,parent1[i].ss));

    for(int j=1;(1<<j)<n;j++){
        for(int i=0;i<n;i++){
            if(table[i][j-1].ff!=-1){
                table[i][j].ff=table[table[i][j-1].ff][j-1].ff;

                table[i][j].ss.ff=min(table[i][j-1].ss.ff,table[table[i][j-1].ff][j-1].ss.ff);
                table[i][j].ss.ss=max(table[i][j-1].ss.ss,table[table[i][j-1].ff][j-1].ss.ss);
            }
        }
    }
}

pii query(int p,int q){
    if(level[p]<level[q]) swap(p,q);

    int mini=INT_MAX,maxi=0;

    int log=1;

    while((1<<log)<=level[p]) log++;

    for(int i=log;i>=0;i--){
        if(level[p]-(1<<i)>=level[q] ){
            mini=min(mini,table[p][i].ss.ff);
            maxi=max(maxi,table[p][i].ss.ss);
            p=table[p][i].ff;
        }
    }

    if(p==q) return mp(mini,maxi);

    for(int i=log;i>=0;i--){
        if(table[p][i].ff!=-1 and table[p][i].ff!=table[q][i].ff){
            mini=min(mini,min(table[p][i].ss.ff,table[q][i].ss.ff));
            maxi=max(maxi,max(table[p][i].ss.ss,table[q][i].ss.ss));
            p=table[p][i].ff;
            q=table[q][i].ff;
        }
    }

    mini=min(mini,min(parent[q].ss,parent[p].ss));
    maxi=max(maxi,max(parent[p].ss,parent[q].ss));

    return mp(mini,maxi);
}

int main()
{
    //FI;FO;
    //FastIO;

    int t; sfi(t);

    int cas=1;
    while(t--){

        //cin>>n;
        sfi(n);
        adjLst.assign(n,vii());
        parent.assign(n,pii());
        parent1.assign(n,pii());
        level.assign(n,0);

        fof(i,1,n){
            int u,v,c;
            //cin>>u>>v>>c;
            sfiii(u,v,c);
            u--,v--;
            adjLst[u].pb(mp(v,c));
            adjLst[v].pb(mp(u,c));
        }

        dfs(-1,0,0,INT_MAX,0);
        init_lca();

        int q; //cin>>q;
        sfi(q);

        printf("Case %d:\n",cas++);

        while(q--){
            int u,v;
            //cin>>u>>v;
            sfii(u,v);
            u--,v--;
            pii ans=query(u,v);
            printf("%d %d\n",ans.ff,ans.ss);
        }
    }

    return 0;
}
