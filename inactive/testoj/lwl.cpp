#include <stdio.h>
#include <math.h>

int main()
{
    int k,m,n;
    scanf("%d", &k);
    int i = 1;
    while (pow(k, i) <= 1000) {
        i++;
    }
    m = i + 1;
    n = i;
    int nre = (int)pow(k, n) % 1000;
    int mre = (int)pow(k, m) % 1000;
    printf("%d\n%d\n", nre,mre);
    while (mre!=nre) {
        m++;
        mre *= k;
        if (mre >= 1000) mre %= 1000;
    }
    printf("%d", m + n);
    return 0;
}
