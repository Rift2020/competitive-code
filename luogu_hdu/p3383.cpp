#include<bits/stdc++.h>
#define maxn 100000005
using namespace std;
int n,q;
vector<int> prime;
bool isComp[maxn];//true即为合数，composite number合数
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=2;i<=n;++i){
        if(isComp[i]==false){
            prime.push_back(i);
        }
        for(const int &j:prime){
            if(j*i>n)break;
            isComp[i*j]=true;
            if(i%j==0)break;
        }
    }
    while(q--){
        int in;
        cin>>in;
        cout<<prime[in-1]<<endl;
    }
    return 0;
}