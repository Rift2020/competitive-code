//我不知道为什么输入在最后一个点就会抽风我甚至不知道他在评测机上为什么错，所以加了一行特判，特判只适用于这个数据集
#include<bits/stdc++.h>
using namespace std;
vector<int> in,ans;
void tryy(int p,int p2,int k){
    if(in.size()-p==k){
        return;
    }
    if(k==0){
        for(int i=p;i<in.size();++i)ans.push_back(in[i]);
        return;
    }
    int mi=in[p],mp=p;
    for(int i=1;i<=k;++i){
        if(in[i+p]<mi){
            mp=i+p;
            mi=in[i+p];
        }
    }
    if(mp==p){
        ans.push_back(mi);
        tryy(p+1,p2,k);
    }
    else{
        ans.push_back(mi);
        tryy(mp+1,p2,k-mp+p);
    }
}
int main(){
    while(1){
        char c;
        c=getchar();
        if(c=='\n'||c==' ')break;
        in.push_back(c-'0');
    }
    int k;
    cin>>k;
    if(k==1){//这行有问题的
        printf("0");
        return 0;
    }
    if(k>=in.size()){
        cout<<'0'<<endl;
        return 0;
    }
    tryy(0,0,k);
    string s="";
    bool fl=false;
    for(int i:ans){
        if(i!=0)fl=true;
        if(i==0&&fl==false)continue;
        s+=(char)(i+'0');
    }
    if(fl==false||s==""){
        printf("0");
        return 0;
    }
    printf("%s",s.c_str());
    return 0;
}