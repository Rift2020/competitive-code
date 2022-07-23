//poj狗都不用（不是
#include<iostream>
#include<unordered_map>
#include<queue>
#define maxn 100005
using namespace std;
unordered_map<char,int> um;
priority_queue<int,vector<int>,greater<int> > pq,cl;
int main(){
    while(1){
        um.clear();
        pq=cl;
        string in;
        getline(cin,in);
        if(in=="END")break;
        for(const char &i:in){
            if(um.find(i)==um.end())um[i]=1;
            else ++um[i];
        }
        for(const auto &i:um){
            pq.push(i.second);
        }
        int ans=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        cout<<8*in.size()<<" ";
        cout<<ans<<" ";
        printf("%.1f\n",(float)8*in.size()/ans);
        
    }
    
    
    return 0;
}