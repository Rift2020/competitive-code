#include<bits/stdc++.h>
using namespace std;
int des[3][3]={1,2,3,8,0,4,7,6,5};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int h(const int a[3][3]){
    int re=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;++j){
            if(a[i][j]!=des[i][j])re++;
        }
    }
    return re;
}
typedef struct{
    int a[3][3];
    int f,g;
}state;
bool operator>(state c,state d){
    return c.f>d.f;
}
bool operator<(state c,state d){
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j){
            if(c.a[i][j]!=d.a[i][j])return c.a[i][j]<d.a[i][j];
        }
    return false;
}
set<state> s;
priority_queue<state,vector<state>,greater<state> > pq;
bool swapp(int a[3][3],int dx,int dy){
    int x,y;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(a[i][j]==0){
                x=i,y=j;
                break;
            }
        }
    }
    int nx=x+dx,ny=y+dy;
    if(nx<0||nx>2||ny<0||ny>2)return false;
    swap(a[x][y],a[nx][ny]);
    return true;
}
int main(){
    string in;
    cin>>in;
    state st;
    int ans;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            st.a[i][j]=in[i*3+j]-'0';
        }
    }
    st.f=h(st.a),st.g=0;
    pq.push(st);
    while(!pq.empty()){
        state now=pq.top();
        pq.pop();
        if(s.find(now)!=s.end())continue;
        s.insert(now);
        if(now.f-now.g==0){
            ans=now.g;
            break;
        }
        for(int i=0;i<4;++i){
            state nex=now;
            if(swapp(nex.a,dx[i],dy[i])){
                nex.g=now.g+1;
                nex.f=now.g+h(nex.a);
                //show(nex.a);
                pq.push(nex);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}