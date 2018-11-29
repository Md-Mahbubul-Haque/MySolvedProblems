#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<long,long>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define MAX 4e18
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};
int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    ff(i,1,t) {
        ll n, x, y, d;
        cin >> n >> x >> y >> d;

        if(true){

            if(abs((y-x))%d==0){
                cout<<abs((y-x))/d<<endl;
            }
            else{
                int lef=INT_MAX,rig=INT_MAX;

                if((n-y)%d==0){
                    lef=(n-y)/d;

                    if((n-x)%d==0){
                        lef+=(n-x)/d;
                    }
                    else{
                        lef+=(n-x)/d;
                        lef++;
                    }
                }
                if((y-1)%d==0){
                    rig=(y-1)/d;

                    if((x-1)%d==0){
                        rig+=(x-1)/d;
                    }
                    else{
                        rig+=(x-1)/d;
                        rig++;
                    }
                }

                ll ans=min(lef,rig);

                if(ans!=INT_MAX)
                    cout<<ans<<endl;
                else cout<<"-1"<<endl;

            }

        }


        /*if ((abs(y - x)) % d == 0) {
            cout <<abs(y-x)/d<<endl;
        }
        else cout<<"-1"<<endl;*/
    }

    return 0;
}
