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
#define INF 1e9
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

string text,pattern;
int n,m;
int cnt;
vi border;

void kmpPreprocess(){
    border[0]=-1;
    int i=0,j=-1;

    while(i<m){
        while(j>=0&&pattern[i]!=pattern[j]) j=border[j];
        i++,j++;
        border[i]=j;
    }
}

string kmp(){
    int i=0,j=0;

    while(i<n){
        while(j>=0&&text[i]!=pattern[j]) j=border[j];

        i++,j++;

        if(i+j==n){

            string temp;

            fb(k,n-(2*j)-1,0) temp+=text[k];
            return (text+temp);

        }
        else if(i+j==n+1){
            string temp;

            fb(k,n-(2*j-1)-1,0) temp+=text[k];
            return (text+temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    border.assign(100001,0);

    while(cin>>text){

        n=text.size();
        int x=n/2;
        fb(i,n-1,x) {
            pattern += text[i];
        }

        m=pattern.size();
        kmpPreprocess();

        cout<<kmp()<<endl;
        pattern.clear();
    }


    return 0;
}
