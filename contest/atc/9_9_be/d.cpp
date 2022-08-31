#include<bits/stdc++.h>
#define repeat(i,n) for(int i = 0;i<(n);i++)
using namespace std;
using ll = long long int;
typedef pair<int,int> pr;//点，第一个x第二个y
set<pr> st;//所有点的集合
unordered_map<int,vector<int> > um;//key是y坐标，vector存的是一排x坐标
vector<int> yl;//y坐标集合
int n,ans;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int x,y;
    repeat(i,n){
        cin>>x>>y;
        yl.push_back(y);
        if(um.find(y)==um.end()){
            vector<int> v={x};
            um[y]=v;
        }
        else{
            um[y].push_back(x);
        }
        st.insert(pr{x,y});
    }
    sort(yl.begin(),yl.end());
    yl.erase(unique(yl.begin(),yl.end()),yl.end());//去重，所以剩下的是排好序的所有y坐标集合
    for(auto &i:um){
        auto itr=upper_bound(yl.begin(),yl.end(),i.first);//这一排点之上的y坐标的首个
        for(int j=0;j<i.second.size();++j){
            for(int k=j+1;k<i.second.size();++k){
                //也就是说i.second[j]和i.second[k]是一排点中的两个x坐标
                for(auto it=itr;it!=yl.end();++it){
                    //(i.second[j],*it)，(i.second[k],*it)这两个点是否有
                    if(st.find(pr{i.second[j],*it})!=st.end()&&st.find(pr{i.second[k],*it})!=st.end())
                        ++ans;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}