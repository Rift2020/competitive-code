#include<bits/stdc++.h>
using namespace std;
struct nn
{
    int am;
    int f;
    bool operator<(const struct nn& a){
        if(f<a.f)return true;
        return false;
    }
};
typedef struct nn nn;
int main(){
    int n,m;
    cin>>n>>m;
    nn a[m];
    for(int i=0;i<m;++i){
        scanf("%d %d",&a[i].f,&a[i].am);
    }
    sort(a,a+m);
    int s=0,ff=0;
    for(int i=0;i<m;++i){
        if(s+a[i].am>=n){
            ff+=(n-s)*a[i].f;
            break;
        }
        s+=a[i].am;
        ff+=a[i].am*a[i].f;
    }
    cout<<ff;
    return 0;
}