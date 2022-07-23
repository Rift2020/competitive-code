#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a;
    vector<char> b;
    int x;
    char c=0;
    do
    {
        cin>>x>>c;
        a.push_back(x);
        b.push_back(c);
    } while (c!='=');
    b.pop_back();
    int s=a[0];
    for(int i=0;i!=b.size();++i){
        if(b[i]=='+')s+=a[i+1];
        else if(b[i]=='-')s-=a[i+1];
        else if(b[i]=='*')s*=a[i+1];
        else if(b[i]=='/'){
            if(a[i+1]==0){
                cout<<"ERROR"<<endl;
                return 0;
            }
            s/=a[i+1];
        }
        else
        {
            cout<<"ERROR"<<endl;
                return 0;
        }
    }
    cout<<s<<endl;
    return 0;
}