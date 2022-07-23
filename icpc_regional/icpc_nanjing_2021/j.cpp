#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
bool isPrime[1005];
vector<int> prime;
vector<int> kp;
int n,a,b,k;
void findkp(int x){
    while(1){
        if(x==1)return;
        if(isPrime[x]){
            kp.push_back(x);
            return;
        }
        for(int i:prime){
            if(x%i==0){
                x/=i;
                kp.push_back(i);
                break;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=1005;++i){
        if(isPrime[i])prime.push_back(i);
        for(ll j=(ll)i*i;j<=1005;j+=i)
            isPrime[j]=false;
    }
    cin>>n;
    while(n--){
        int ans=0;
        cin>>a>>b;
        if(a<b)swap(a,b);
        k=a-b;
        kp.clear();
        findkp(k);
        sort(kp.begin(),kp.end(),greater<int>());
        for(int now:kp){
            int mod=a%now;
            if(a%now==0){
                a/=now;
                b/=now;
                ++ans;
            }
            else if(mod<=now-mod){
                a-=mod;
                b-=mod;
                ans+=mod;
                a/=now;
                b/=now;
                ++ans;
            }
            else{
                a+=now-mod;
                b+=now-mod;
                ans+=now-mod;
                a/=now;
                b/=now;
                ++ans;
            }
        }
        ans+=b-1;
        cout<<ans<<endl;
    }
    return 0;
}