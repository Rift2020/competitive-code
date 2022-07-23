#include<bits/stdc++.h>
using namespace std;
int l,w,h,x1,y1,z1,x2,y2,z2;
int wch(int &x,int &y,int &z){
    x=abs(x),y=abs(y),z=abs(z);
    if(z==0)return 1;
    if(z==h)return 4;
    if(y==0)return 2;
    if(y==w)return 5;
    if(x==0)return 3;
    if(x==l)return 6;
}
int main(){
    cin>>l>>w>>h>>x1>>y1>>z1>>x2>>y2>>z2;
    int t1=wch(x1,y1,z1),t2=wch(x2,y2,z2);
    double dx=abs(x1-x2),dy=abs(y1-y2),dz=abs(z1-z2);
    if(t1==t2){
        cout<<sqrt(dx*dx+dy*dy+dz*dz)<<endl;
    }
    else if(t1%3==t2%3){
        if(t1%3==1){
            cout<<sqrt(dx*dx+(h+y1+y2)*(h+y1+y2))<<endl;
        }
        else if(t1%3==2){
            cout<<sqrt(dx*dx+(w+z1+z2)*(w+z1+z2))<<endl;
        }
        else{
            cout<<sqrt(dz*dz+(l+y1+y2)*(l+y1+y2))<<endl;
        }
    }
    else{
        if(t1%3>t2%3){
            swap(t1,t2);
            swap(x1,x2);
            swap(y1,y2);
            swap(z1,z2);
        }
        if(t1%3==1&&t2%3==2){
            cout<<sqrt((dy+dz)*(dy+dz)+dx*dx);
        }
        else if(t1%3==0&&t2%3==2){
            cout<<sqrt((dy+dx)*(dy+dx)+dz*dz);
        }
        else {
            cout<<sqrt((dx+dz)*(dz+dx)+dy*dy);
        }
    }
    cout<<t1<<" "<<t2<<endl;
    return 0;
}