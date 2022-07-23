#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=x*(a/b);
}
int t,a,b,c;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int g=gcd(a,b);
        if(c%g!=0){
            cout<<-1<<endl;
        }
        else{
            int x,y;
            exgcd(a,b,x,y);
            int cnt=0;
            x=x*c/g,y=y*c/g;
            //cout<<':'<<x<<" "<<y<<endl;
            int le=-x/(b/g);
            if(le>0||-x%(b/g)==0||((float)-x/(b/g)>0&&le==0))le++;//保证向右取整
            int ri=y/(a/g);
            if(ri<0||y%(a/g)==0||((float)y/(a/g)<0&&ri==0))ri--;//保证向左取整
            //cout<<'>'<<le<<" "<<ri<<endl;
            cnt=ri-le+1;
            int xmin=x+(b/g)*le;
            int xmax=x+(b/g)*ri;
            int ymin=y-(a/g)*ri;
            int ymax=y-(a/g)*le;
            if(cnt>0){
                cout<<cnt<<" "<<xmin<<" "<<ymin<<" "<<xmax<<" "<<ymax<<endl;
            }
            else{
                cout<<xmin<<" "<<ymin<<endl;
            }
        }
    }
    
    
    return 0;
}