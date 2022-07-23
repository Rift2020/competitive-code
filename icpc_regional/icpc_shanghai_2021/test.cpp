#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define int long long
using namespace std;
using ll = long long;
const int mo = 998244353;
const int N = 100010;
int l = 0;
int last[N] = {0}, sum[N] = {0}, du[N] = {0};
bool vis[N] = {false};
int pre[N << 1], other[N << 1];
queue<int> que;
ll fact[N];
ll inline fpow(ll x,ll n){
    ll re=1;
    while(n){
        if(n&1)
            re=x*re%mo;
        x=x*x%mo;
        n>>=1;
    }
    return re;
}
ll C(ll m,ll n){
    ll fm=fact[m]*fact[n-m];
    fm%=mo;
    fm=fpow(fm,mo-2);
    ll fz=fact[n];
    return (fz*fm)%mo;
}
ll f(ll k)
{
    ll re=1;
    for(ll i=k;i>=2;i-=2){
        re=(re*C(2,i))%mo;
    }
    ll fm=fact[k/2];
    fm%=mo;
    fm=fpow(fm,mo-2);
    return (re*fm)%mo;
}
void connect(int x, int y) {
    l++;
    pre[l] = last[x];
    last[x] = l;
    other[l] = y;
}

signed main(){
    ios::sync_with_stdio(false);
    fact[0]=1;
    int n;
    cin >> n;
    rep(i,1,n)fact[i]=fact[i-1]*i%mo;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        connect(a, b);
        connect(b, a);
        du[a]++;
        du[b]++;
    }
    //
    //for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= n; i++) 
        if (du[i] == 1) que.push(i);
    //
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        int p, q; 
        q = last[cur]; du[cur]--; 
        while (q) {
            p = other[q];
            
            if (!vis[p]) {
                du[p]--;
                sum[p] ++;
                if ((du[p] == 1) && (sum[p] % 2 == 0)) {
                    sum[p] ++;
                    int tmp_q, tmp_p;
                    tmp_q = last[p]; du[p]--; vis[p] = true;
                    while (tmp_q) {
                        tmp_p = other[tmp_q];
                        if (!vis[tmp_p]) {
                            du[tmp_p]--; 
                            if (du[tmp_p] == 1) que.push(tmp_p);
                        }
                        tmp_q = pre[tmp_q];
                    }
                } else if ((du[p] == 1) && (sum[p] % 2 == 1)) {
                    que.push(p);
                } else if (du[p] != 0) sum[p]++; 
                if (du[p] == 0) vis[p] = true;
            }
            q = pre[q];
        }
    }  
   // for (int i = 1; i <= n; i++) cout << i << ' ' << sum[i] << endl;
    ll s=1;
    for (int i = 1; i <= n; i++){
        if(sum[i]==0)
        {
            continue;
        }
        else{
            s=(s*f(sum[i]))%mo;
        }
    }
    cout<<s;
    return 0;
}