#include<bits/stdc++.h>
#define maxn 10000005
using namespace std;
bool isPrime[maxn];
vector<int> prime;
int main(){
    int n;
    cin>>n;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n;++i){
        if(isPrime[i]){
            prime.push_back(i);
        }
        for(long long j=(long long)i*i;j<=n;j+=i){
            isPrime[j]=false;
        }
    }
    cout<<prime.size()<<endl;
    
    return 0;
}