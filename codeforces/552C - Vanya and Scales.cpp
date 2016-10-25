#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<iostream>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
int ak[100000];
int main(void)
{
        LL n,m;
        while(scanf("%lld %lld",&n,&m)!=EOF)
        {
                int flag = 0;
                int cn = 0;
                while(m)
                {
                        ak[cn++] = m%n;
                        m/=n;
                }
                int d = 0;
                if(n==2)printf("YES\n");
                else
                {for(int i = 0; i < cn; i++)
                {
                      ak[i]+=d;
                      if(ak[i]==n-1)
                      {
                          ak[i]++;
                      }
                      d = ak[i]/n;
                      ak[i]=ak[i]%n;
                      if(ak[i]!=0&&ak[i]!=1)
                        flag = 1;
                }
                if(flag)printf("NO\n");
                else printf("YES\n");}
        }
        return 0;
}
