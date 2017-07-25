#include<bits/stdc++.h>
using namespace std;
char str[1000005];
int num[1000005];
int main(void)
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str);
        int l = strlen(str);
        for(int i = 0; i < l; i++)
            num[i] = str[i] - '0';
        bool flag = false;
        for(int i = 0; i < l; i++)
        {
            if(num[i] != 9)
                flag = true;
        }
        if(!flag)
        {
            printf("1");
            for(int i = 0; i < l-1; i++)
                printf("0");
            printf("1");
        }
        else
        {
            if(l == 1)
                printf("%d",num[0]+1);
            else
            {
                if(l%2)
                {
                    int f = 0;
                    for(int i = (l/2)-1; i >= 0; i--)
                    {
                        if(num[i] < num[l -i-1])
                        {
                            f = 1;
                            break;
                        }
                        else if(num[i] > num[l-i-1])
                        {
                            f = 2;
                            break;
                        }
                    }
                    if(f == 0||f == 1)
                        num[l/2]++;
                    int d = 0;
                    for(int i = l/2; i >= 0; i--)
                    {
                        num[i] += d;
                        d = num[i]/10;
                        num[i]%=10;
                    }
                    for(int i = 0; i <= l/2-1; i++)
                        num[l-i-1] = num[i];
                }
                else
                {
                   int f = 0;
                    for(int i = (l/2)-1; i >= 0; i--)
                    {
                        if(num[i] < num[l -i-1])
                        {
                            f = 1;
                            break;
                        }
                        else if(num[i] > num[l-i-1])
                        {
                            f = 2;
                            break;
                        }
                    }
                    if(f == 0||f == 1)
                        num[l/2-1]++;
                    int d = 0;
                    for(int i = l/2-1; i >= 0; i--)
                    {
                        num[i] += d;
                        d = num[i]/10;
                        num[i]%=10;
                    }
                    for(int i = 0; i <= l/2-1; i++)
                        num[l-i-1] = num[i];
                }
                for(int i = 0;i < l;i++)
                {
                    printf("%d",num[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
