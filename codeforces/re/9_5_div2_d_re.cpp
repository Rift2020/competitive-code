#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > pq,cl;
int ss;
int t,s,n;
string str;
bool fl;
void output(){
    for(int i=0;i<ss;++i)cout<<1<<" ";
    while(!pq.empty())cout<<pq.top()<<" ",pq.pop();
    if(s!=0)cout<<s<<" ";
    cout<<endl;
}
int pow(int x,int n){
    int re=1;
    for(int i=0;i<n;++i)re*=x;
    return re;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        ss=0;
        pq=cl;
        cin>>s>>n;
        fl=false;
        while(s>0){
            if(pq.size()+ss+1==n){
                fl=true;
                break;
            }
            str=to_string(s);
            int p=pow(10,str.size()-1);
            s-=p;
            if(p==1)ss++;
            else pq.push(p);
        }
        if(fl){
            output();
            continue;
        }
        while(pq.size()+ss<n){
            s=pq.top();
            pq.pop();
            int d=s/10;
            for(int i=0;i<10;++i){
                if(pq.size()+ss+1==n){
                    fl=true;
                    break;
                }
                s-=d;
                if(d==1)++ss;
                else pq.push(d);
            }
            if(fl)break;
        }
        output();
    }
    
    
    return 0;
}