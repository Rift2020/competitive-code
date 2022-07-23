#include<bits/stdc++.h>
#define maxsize 1000005//栈的最大容量，显然这题里，不会超过maxn
#define maxn 100005
using namespace std;
template<typename T>
struct stk{//栈的板子，使用它相比stl，便于获取栈顶第二个点
    T a[maxsize];
    int tp;
    stk(){
        tp=-1;
    }
    void push(const T &t){
        a[++tp]=t;
    }
    void pop(){
        if(tp>-1)--tp;
    }
    T& top(){
        T &re=a[tp];
        return re;
    }
    int size(){
        return tp+1;
    }
    bool empty(){
        if(tp==-1)return true;
        else return false;
    }
    void clear(){
        tp=-1;
    }
};
struct po{
    double x,y;
};
bool operator<(const po &a,const po &b){
    if(a.x!=b.x)return a.x<b.x;
    else return a.y<b.y;
}

bool operator>(const po &a,const po &b){
    if(a.x!=b.x)return a.x>b.x;
    else return a.y>b.y;
}

po a[maxn];
int n;
stk<po> st;
double cross_product(po a1,po b1,po a2,po b2){//叉积计算，a1b1是第一个向量，a2b2是第二个
    double a=b1.x-a1.x;
    double b=b1.y-a1.y;
    double c=a2.x-b2.x;
    double d=a2.y-b2.y;
    return a*d-b*c;
}
void solve(){
    //Andrew
    st.push(a[0]);
    for(int i=1;i<n;++i){
        po now=a[i];
        while(1){//用while1便于反复pop不满足的点
            if(st.size()==1){
                st.push(now);
                break;
            }
            else{
                po a=st.a[st.tp-1],b=st.top();
                if(cross_product(a,b,b,now)>0){
                    st.push(now);
                    break;
                }
            }
            st.pop();
        }
    }
}
double cal(){//遍历计算栈中的周长
    double re=0;
    po a=st.a[0];
    for(int i=1;i<st.size();++i){
        po b=st.a[i];
        double dx=a.x-b.x;
        double dy=a.y-b.y;
        re+=sqrt(dx*dx+dy*dy);
        a=b;
    }
    return re;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        double x,y;
        scanf("%lf%lf",&x,&y);
        a[i]=po{x,y};
    }
    sort(a,a+n);
    solve();
    //此时栈中是下凸包
    double ans=cal();
    st.clear();
    sort(a,a+n,greater<po>());
    solve();
    //此时栈中是上凸包
    ans+=cal();
    printf("%.2lf",ans);

    return 0;
}