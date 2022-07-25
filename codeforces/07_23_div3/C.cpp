#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200005
using namespace std;
int t,n;
typedef struct{
    int a[6];
    int now;
    int all;
    double rat;
}st;
bool operator<(st a,st b){
    if(max(a.rat,b.rat)>=0.5)return a.rat>b.rat;
    return (a.all-a.now)<(b.all-b.now);
}
vector<st> v;
void inline turn(st& stt,int x){
    stt.now=stt.a[x];
    stt.rat=(double)stt.now/stt.all;
}
void solve(){
    int ma=0;
    for(int i=0;i<5;++i){
        for(st &j:v){
            turn(j,i);
        }
        sort(v.begin(),v.end());
        int nnow=0,nall=0,nn=0;
        for(st &j:v){
            nnow+=j.now;
            nall+=j.all-j.now;
            if(nnow<=nall)break;
            ++nn;
        }
        ma=max(ma,nn);
    }
    cout<<ma<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n;
        v.clear();
        for(int j=0;j<n;++j){
            string in;
            st inst;
            for(int &k:inst.a)k=0;
            inst.all=0;
            cin>>in;
            bool fl=true;
            for(char &c:in){
                if(c>'e'){
                    fl=false;
                    break;
                }
                inst.a[c-'a']++;
                inst.all++;
            }
            if(fl==false)continue;
            v.push_back(inst);
        }
        solve();
    }
    return 0;
}