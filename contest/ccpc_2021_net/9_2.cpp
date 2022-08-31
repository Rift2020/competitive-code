#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct point{
    int x,y;
};
bool operator<(const point &a,const point &b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
map<point,int> us,cl;
int t,n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        us=cl;
        ll ans=0;
        point now;
        now.x=0,now.y=0;
        us[now]=1;
        for(const char &c:s){
            if(c=='U'){
                now.y++;
            }
            else if(c=='D'){
                now.y--;
            }
            else if(c=='L'){
                now.x--;
            }
            else if(c=='R'){
                now.x++;
            }
            if(us.find(now)!=us.end()){
                ans+=us[now];
                us[now]++;
            }
            else{
                us[now]=1;
            }
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}