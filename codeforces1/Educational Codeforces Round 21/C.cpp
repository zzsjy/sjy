#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int ans[105];
int bns[105];
typedef struct node
{
    int id;
    int now;
    int val;
}ss;
ss a[105];
bool cmp(node p,node q)
{
    return p.val > q.val;
}
int ask[105];
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    {  int sum = 0;int all = 0;
       for(int i = 0;i < n;i++)
       {
           scanf("%d",&ans[i]);
           if(ans[i]%2)
            a[i].now = ans[i]/2+1;
           else a[i].now = ans[i]/2;
           sum += a[i].now;
           a[i].id = i,a[i].val = ans[i];
           all += ans[i];
       }
       sort(a,a+n,cmp);
       if(sum > m||m > all)
        printf("-1\n");
       else
       {  int v = m-sum;
          int i = 0;
          while(v)
          {
              if(v >= a[i].val - a[i].now)
                v -= a[i].val - a[i].now,a[i].now = a[i].val;
              else
              {
                  a[i].now += v;
                  v = 0;
              }
              i = i+1;
              i%=n;
          }
          for(int i = 0;i < n;i++)
          {
              ask[a[i].id] = a[i].now;
          }
          printf("%d",ask[0]);
          for(int i = 1;i < n;i++)
            printf(" %d",ask[i]);
          printf("\n");
       }
    }
    return 0;
}
