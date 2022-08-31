/**
 *    author:  Rift
 *    created: 2022.08.23  22:23
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define int ll
#define maxn 100005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
multiset<ll> ms;
int t,n,m;
int a[maxn],p[maxn];
int s[maxn];
int b[maxn];
int y[maxn];
int mo[maxn];
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return g;
}
ll exCRT(long long a[], long long n[], int k){
    ll anow=a[1],nnow=n[1];
    for(int i=2;i<=k;++i){
        ll x,y,g;
        g=exgcd(nnow, n[i], x, y);
        if((a[i]-anow)%g!=0)return -1;
        x=x*((a[i]-anow)/g);
        anow= x * nnow + anow;
        nnow=nnow/g*n[i];//nnow=lcm(nnow,n[i])
        anow= (anow % nnow + nnow) % nnow;
    }
    return (anow % nnow + nnow) % nnow;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>t;
    while(t--){
        ms.clear();
        cin>>n>>m;
        rep(i,1,n)cin>>a[i];
        rep(i,1,n)cin>>p[i];
        rep(i,1,n)cin>>s[i];
        rep(i,1,m){
            int in;
            cin>>in;
            ms.insert(in);
        }
        rep(i,1,n){
            if(*ms.begin()>=a[i]){
                b[i]=*ms.begin();
                ms.erase(ms.begin());
            }
            else{
                b[i]=*(--ms.lower_bound(a[i]));
                ms.erase(--ms.lower_bound(a[i])--);
            }
            ms.insert(s[i]);
        }
		bool fl=true;
		rep(i,1,n){
			int x,b_;
			cout<<"pb:"<<p[i]<<" "<<-b[i]<<endl;
			int g=exgcd(p[i],-b[i],x,y[i]);
			g=-abs(g);
			if(a[i]%g!=0){
				fl=false;
				break;
			}
			x=-a[i]/g*x;
			b_=-b[i]/g;
			x=(x%b_+b_)%b_;
			cout<<"x:"<<x<<endl;
			mo[i]=(p[i]/g);
			y[i]=(-a[i]-x*p[i])/-b[i];
		cout<<y[i]<<" "<<mo[i]<<endl;
		}
		int ans;
		if(fl)
			ans=exCRT(y,mo,n);
		if(fl==false||ans==-1){
			cout<<-1<<endl;
		}
		else
			cout<<ans<<endl;
    }


    return 0;
}
