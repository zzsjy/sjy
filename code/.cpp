#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
typedef long long LL;
using namespace std;
int ans[18005];
int cnt[18005];
int cnt2[18005];
int b[18005];
int ask[18005];
int main(void)
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&ans[i]);
    }
    memset(cnt,0,sizeof(cnt));
    for(i = 1; i <= n; i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(j = 1; j <= n; j++)
        {
            if(ans[i] == ans[j])
                b[j] = 0;
            else if(ans[i]>ans[j])
                b[j] = -1;
            else b[j] = 1;
        }
        int sum = 8000;
        for(j = i; j >= 1; j--)
        {
            sum+=b[j];
            cnt[sum]++;
        }
        sum = 8000;
        for(j = i; j <= n; j++)
        {
            sum+=b[j];
            ask[i]+=cnt[16000-sum];
        }

    }
    printf("%d",ask[1]);
    for(i = 2; i <= n; i++)
    {
        printf(" %d",ask[i]);
    }
    printf("\n");
    return 0;
}
