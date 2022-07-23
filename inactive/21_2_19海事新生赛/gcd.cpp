#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=1,y=1,t;
    cout<<"1";
    for(int i=2;i<=20;++i){
        cout<<" "<<y;
        t=y;
        y+=x;
        x=t;
    }
    cout<<endl;
    return 0;
}