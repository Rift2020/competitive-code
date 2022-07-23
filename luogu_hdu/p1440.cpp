#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;
typedef pair<int,int> pr;//value,index
int n,m;
int a[maxn];
deque<pr> dq;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    printf("0\n");
    for(int i=0;i<n-1;++i){
        if(dq.front().second<i-m+1)dq.pop_front();//队首超出m范围出队
        while(!dq.empty()&&dq.back().first>a[i])dq.pop_back();//保持单调
        dq.push_back(pr{a[i],i});
        printf("%d\n",dq.front().first);
    }
    return 0;
}