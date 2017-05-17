#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans[100005];
LL sum[100005];
int main(void)
{
    int n;
    scanf("%d",&n);
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&ans[i]);
        sum[i] = sum[i-1] + ans[i];
    }
    if(sum[n]%(LL)2||n == 1)
    {
        printf("NO\n");
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(sum[i] == sum[n]/(LL)2)
            {
                printf("YES\n");
                return 0;
            }
        }
        LL u = sum[n]/(LL)2;
        for(int i = 1; i <= n; i++)
        {
            int id = -1;
            int l = 0,r = i-1;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(sum[mid] +  ans[i] <= u)
                {
                    id = mid;
                    l = mid + 1;
                }
                else r = mid-1;
            }
            if(id!=-1&&sum[id] + ans[i] == u)
                flag = true;
            l = i+1,r = n+1;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(sum[n] - sum[mid-1]+  ans[i] <= u)
                {
                    id = mid;
                    r = mid - 1;
                }
                else l = mid+1;
            }
            if(id!=-1&&sum[n] - sum[id-1]+  ans[i] == u)
                flag = true;
        }
        if(flag)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
# Array Division
[题目链接][1]


  [1]: http://codeforces.com/contest/808/problem/D
##题意
n个数，然后你可以移动里面的一个数，然后再将序列分成两段，问是否可能这两段的和相同。
##思路
先求出序列的前缀和，然后枚举移动哪个，要么放在当前序列的前面，要么放后面，然后二分检验是否符合要求。
复杂度$n*log(n)$
*/
