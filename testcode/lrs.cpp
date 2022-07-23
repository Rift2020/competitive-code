#include<bits/stdc++.h>
using namespace std;
const int n=8;
int num[n];
string name[]={"汉堡","超级小导","feelmelove","飞飞","秦","香辣牛筋","爱笙","可莉来咯"};
string job[]={"船长","工程","厨子","医生","牧师","猎人","枪手","导航"};
int main(){
    for(int i=0;i<8;++i)num[i]=i;
    srand(time(NULL));
    random_shuffle(num,num+n);
    for(int i=0;i<8;++i){
        cout<<name[i]<<" : "<<job[num[i]]<<endl;
    }
    
    
    
    return 0;
}