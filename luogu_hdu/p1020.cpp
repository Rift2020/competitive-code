#include<bits/stdc++.h>
using namespace std;
int in;
vector<int> v;
vector<int> lis;
vector<int> ls;
int now=-1,ans=1;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>in)v.push_back(in);
    lis.push_back(*v.begin());
    for(int i=1;i<v.size();++i){
        if(v[i]<=lis[lis.size()-1])lis.push_back(v[i]);
        else{
            *upper_bound(lis.begin(),lis.end(),v[i],greater<int>())=v[i];
        }
    }
    ls.push_back(*v.begin());
    for(int i=1;i<v.size();++i){
        if(v[i]>ls[ls.size()-1])ls.push_back(v[i]);
        else{
            *lower_bound(ls.begin(),ls.end(),v[i])=v[i];
        }
    }
    cout<<lis.size()<<endl;
    cout<<ls.size()<<endl;
    return 0;
}