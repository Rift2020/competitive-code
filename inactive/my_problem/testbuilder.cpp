#include<bits/stdc++.h>
#define maxn 100
using namespace std;

int main(){
    freopen("www1.in","w",stdin);    
    int n=rand()%maxn;
    cout<<n<<endl;
    int more=0;
    for(int i=1;i<=n;++i){
        if(n-i+1==more){
            while(more--)cout<<"}"<<" ";
            break;
        }
        int op;
        if(more>0)op=rand()%4;
        else op=rand()%3;

        if(op==0)cout<<"if"<<" ";
        else if(op==1)cout<<"else"<<" ";
        else if(op==2){
            cout<<"{"<<" ";
            ++more;
        }
        else if(op==3){
            cout<<"}"<<" ";
            --more;
        }
    }
    return 0;
}