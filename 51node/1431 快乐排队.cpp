#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<map>
#include<stack>
#include<string.h>
#include<iostream>
#define FOR(i,n) for (i = 0;i < n;i++)
#define SC(n) scanf("%d",&n);
using namespace std;
const int BufferSize=1<<16;
char buffer[BufferSize],*head,*tail;
inline char Getchar()
{
    if(head==tail)
    {
        int l=fread(buffer,1,BufferSize,stdin);
        tail=(head=buffer)+l;
    }
    return *head++;
}
inline int read()
{
    int x=0,f=1;
    char c=Getchar();
    for(; !isdigit(c); c=Getchar()) if(c=='-') f=-1;
    for(; isdigit(c); c=Getchar()) x=x*10+c-'0';
    return x*f;
}
int ans[500000];
map<int,int>my;
int main(void)
{
    int c;
    c = read();
    int flag = 0;
    int i;
    FOR(i,c)
    {
        ans[i] = read();
        ans[i] = ans[i]+i;
    }
    sort(ans,ans+c);
    int x = ans[0];
    for(i = 1; i < c; i++)
    {
        if(ans[i]==x)
        {
            flag = 1;break;
        }
        x = ans[i];
    }
    if(flag)printf("Sad\n");
    else printf("Happy\n");
    return 0;
}
