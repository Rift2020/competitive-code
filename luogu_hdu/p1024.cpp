#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
bool eq(double a,double b){
    if(fabs(a-b)<0.001)return true;
    return false;
}
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
double f_(double x){
    return 3*a*x*x+2*b*x+c;
}
double Newton_next(double x){
    return x-f(x)/f_(x);
}
double solve(double l,double r){
    double x=(l+r)/2;
    while(1){
        double nx=Newton_next(x);
        if(eq(x,nx))return x;
        x=nx;
    }
}
int main(){
    int s=0;
    cin>>a>>b>>c>>d;
    for(int i=-100;i<100;++i){
        if(f(i)==0){
            printf("%.2f ",(float)i);
            ++s;
        }
        else if(f(i)*f(i+1)<0){
            printf("%.2f ",solve(i,i+1));
            ++s;
        }
        if(s==3)break;
    }
    
    
    return 0;
}