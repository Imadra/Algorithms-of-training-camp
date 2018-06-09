#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<utility>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#define inf 1000000000
//#define f first
//#define s second
using namespace std;
int l, n, prime[100009];
int main ()
{
    cin>>l>>n;
    for(int i = 2; i <= n; i++)
        prime[i] = 1;
    for(int i = 1; i * i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= n; j+=i)
                prime[j] = 0;
        }
    }
    int ans = 0 ;
    for(int i = l; i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = 1; j <= 35000; j++)
            {
                int x = i - j * j;
                int y = sqrt(x);
                if(y * y == x)
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
}
