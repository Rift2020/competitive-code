#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

using namespace std;
using ll = long long;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int s=0;s<=6;++s){
        for(int f=0;f<60;++f){
            for(int m=0;m<60;++m){
                double x=s*30+(double)f/2+(double)m/120;
                double y=(double)m/10+6*f;
                double z=6*m;
                double a=fabs(y-x);
                double b=fabs(z-y);
                if(a>180)a-=180;
                if(b>180)b-=180;
                if(fabs(a-2*b)<0.00000001){
                    cout<<s<<" "<<f<<" "<<m<<endl;
                }
            }
        }
    }
    
    
    
    return 0;
}