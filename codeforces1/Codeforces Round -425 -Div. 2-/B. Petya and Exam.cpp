/*# B. Petya and Exam
[题目链接][1]


  [1]: http://codeforces.com/problemset/problem/832/B
##题意
给你一串字符，在这个串中所有出现的字符都是$good$字符，未出现的都是$bad$字符，
然后给你另一串字符，这个字符串中有两个特殊的字符，一个是$?$这个字符只能被$good$字符代替，另一个是$*$这个能被忽略，或者被$bad$字符组成的字符串代替.
然后给你n个字符串，问你是否能通过代替原本串中的符号来变得。
##思路
首先判断原本串中是否存在$*$字符如果不存在，那么下面的串的长度就应该和原本串的长度相等。如果存在的话，那么要检查的串的长度必须大于等于原串的长度-1。
然后贪心判定，两串同时从头开始扫，如果原本串中的为$*$那么当前串中的剩下的大于原本串的长度并且为‘bad’则加入$*$,否则跳过$*$继续匹配，$?$是很好处理的。
最后只要判断两串是否都能跑完。复杂度$O(n)$*/
```
#include<bits/stdc++.h>
using namespace std;
char str1[30];
char str2[100005];
char str3[100005];
bool flag[30];
bool f = false;
bool check(int l);
int main(void)
{
    memset(flag,0,sizeof(flag));
    scanf("%s",str1);
    scanf("%s",str2);
    for(int i = 0; i < strlen(str1); i++)
        flag[str1[i] - 'a']++;
    int n;
    scanf("%d",&n);
    int l = strlen(str2);
    for(int i = 0; i < l; i++)
        if(str2[i] == '*')
            f = true;
    while(n--)
    {
        scanf("%s",str3);
        if(check(l))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
bool check(int l)
{
    if(!f)
    {
        if(strlen(str3) != l)
            return false;
    }
    else
    {
        if(strlen(str3) < l-1)
            return false;
    }
    //printf("1\n");
    int z = 0;
    int k = strlen(str3);
    //int ff = 0;
    int i;
    for( i = 0; i < l&&z < k+1;)
    {
        if(str2[i] == '*'&&k-l >= 0)
        {
            //printf("111\n");
            while(!flag[str3[z]-'a']&&z < k&&l-i < k-z+1)
                z++;
        }
        //printf("%d\n",z);
        if(str2[i] == '*')
            i++;
        if(i >= l||z >= k+1)
            break;
        if(str2[i] == '?')
        {
            if(!flag[str3[z]-'a'])
                return false;
            else
                i++,z++;
        }
        else
        {
            if(str2[i] != str3[z])
                return false;
            else i++,z++;
        }
    }
    if(f&&(i < l||z < k))
        return false;
    return true;
}


```
