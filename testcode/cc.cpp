#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n,cnt;
int a[N],vis[N];

void f(int k)
{
    if (cnt==n) return;
    if (k==10)
    {
        if (fabs(a[1]*1.0/(a[2]*10+a[3])+a[4]*1.0/(a[5]*10+a[6])-(a[7]*1.0/(a[8]*10+a[9])))<=1e-6)
        {
            cout<<a[1]<<"/"<<a[2]<<a[3]<<"+"<<a[4]<<"/"<<a[5]<<a[6]<<"="<<a[7]<<"/"<<a[8]<<a[9]<<endl;
            cnt++;
        }
        return;
    }
    for (int i=1;i<=9;i++)
    {
        if (vis[i]==0)
        {
            vis[i]=1;
            a[k]=i;
            f(k+1);
            vis[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    f(1);
    return 0;
}