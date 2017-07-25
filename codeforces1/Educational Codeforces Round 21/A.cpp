#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    scanf("%d",&n);
    int t = 1;
    int s = n;
    while(s)
    {
        s/=10;
        if(s == 0)
            break;
        t*=10;
    }
    int f = n/t;
    f++;
    f*=t;
    printf("%d\n",f-n);
    return 0;
}
