#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
#define int long longusing namespace std;using ll = long long;int a[maxn];
int d[maxn*4];
int b[maxn*4];
void build(int s,int t,int p){
	if(s==t){
		d[p]=a[s];
		return;
	}
	int m=s+((t-s)>>1);//等价于(s+t)/2但可以防止溢出
	build(s,m,p*2),build(m+1,t,p*2+1);
	d[p]=d[p*2]+d[p*2+1];
}
int getsum(int l, int r, int s, int t, int p) {
	if (l <= s && t <= r) return d[p];
	int m = s + ((t - s) >> 1);
	if (b[p]) {
		d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
		b[p*2]+=b[p],b[p*2+1]+=b[p];
		b[p]=0;
	}
	int sum = 0;
	if (l <= m) sum = getsum(l, r, s, m, p * 2);
	if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
	return sum;
}
void update(int l, int r, int k, int s, int t, int p) {
	if (l <= s && t <= r) {
		d[p] += (t - s + 1) * k, b[p] += k;
		return;
	}
	int m = s + ((t - s) >> 1);
	if (s!=t&&b[p]) {
		d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
		b[p*2]+=b[p],b[p*2+1]+=b[p];
		b[p]=0;
	}
	if (l<=m)update(l,r,k,s,m,p*2);
	if (r>m)update(l,r,k,m+1,t,p*2+1);
	d[p]=d[p*2]+d[p*2+1];
}
int n,m;signed main(){	ios::sync_with_stdio(false);	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
	}
	build(1,n,1);	rep(i,1,m){
		int op,x,y,k;
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			update(x,y,k,1,n,1);
		}
		else if(op==2){
			cin>>x>>y;
			cout<<getsum(x,y,1,n,1)<<endl;
		}
	}			return 0;}