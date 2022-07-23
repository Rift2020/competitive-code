#include<bits/stdc++.h>
#define maxsize 1000005
using namespace std;
template<typename T>
struct stk{
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
int main(){
    stk<int> st;
    
    
    return 0;
}