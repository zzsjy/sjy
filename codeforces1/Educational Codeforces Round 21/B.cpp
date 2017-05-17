#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double d[300000];
double cnt[300000];
int main(void)
{
    int k,n;
    scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++)
    {
       scanf("%lf",&d[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        int l = max((i - k + 1),1);
        int r = min(i,n-k + 1);
        cnt[i] = max(0,r-l+1);
    }
    double sum = 0;
    double u = n-k+1;
    for(int i = 1;i <= n;i++)
    {
       sum += cnt[i]/u*d[i];
       //printf("%lf ",cnt[i]);
    }
    printf("%.10f\n",sum);
    return 0;
}
