#include<bits/stdc++.h>
using namespace std;
class BigInt{
    private:
        int data[105];
    public:
        BigInt(){
            memset(data,0,sizeof(data));
        }
        friend ostream &operator<<(ostream &output,const BigInt &a){
            bool f=0;
            for(int i=104;i>=0;--i){
                if(f==0&&a.data[i]==0)continue;
                if(f==0&&a.data[i]!=0)f=1;
                output<<a.data[i];
            }
            return output;
        }
        friend istream &operator>>(istream &input,BigInt &a){
            string s;
            input>>s;
            for(int i=s.size()-1,j=0;i>=0;--i,++j){
                a.data[j]=s[i]-'0';
            }
            for(int i=s.size();i<105;++i)a.data[i]=0;
            return input;
        }
        BigInt operator+(const BigInt &a){
            BigInt bi;
            int j=0;
            for(int i=0;i<105;++i){
                int h=a.data[i]+this->data[i]+j;
                bi.data[i]=h%10;
                j=h/10;
            }
            return bi;
        }
};
int main(){
    BigInt a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    cout<<a+b;
    
    
    return 0;
}