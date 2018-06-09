#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#define inf 1000*1000*1000
#define mod 1000000007
#define ff first
#define ss second
#define mp  make_pair
using namespace std;
long long d[2009][2009], n, m, sum, a[39][50009], ma=-inf;
int bit(int x, int i)
{
    if (i < 0)
        return 0;
    else
    {
        int y = x & (1 << i);
        if (y != 0)
            return 1;
        else
            return 0;
    }
}
// можно ли из p1 получить p2
bool can(int p1, int p2)
{
    int b[9];
    for (int i = 0; i < n - 1; i++)
    {
        b[1] = bit(p1, i);
        b[2] = bit(p1, i + 1);
        b[3] = bit(p2, i);
        b[4] = bit(p2, i + 1);

        if ((b[1] == 1) && (b[2] == 1) && (b[3] == 1) && (b[4] == 1))
        {
            // квадрат в строках i и i + 1 черный
            return false;
        }

        if ((b[1] == 0) && (b[2] == 0) && (b[3] == 0) && (b[4] == 0))
        {
            // квадрат в строках i и i + 1 белый
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    if(m<n)
        swap(m, n);
    for (int p1 = 0; p1 < (1 << n); p1++)
        for (int p2 = 0; p2 < (1 << n); p2++)
        {
            if(can(p1, p2))
                d[p1][p2] = 1;
            else
                d[p1][p2] = 0;
        }
    //cout<<bit(0, 1)<<endl;
    /*for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }*/
    //cout<<endl;
    a[1][0] = 1;//, cout<<1<<" ";
    for(int p2=1; p2<(1<<n); p2++)
        a[1][p2]=1;//, cout<<1<<" ";
    //cout<<endl;
    for(int i=2; i<=m+1; i++)
    {
        for(int p1=0; p1<(1<<n); p1++)
        {
            sum=0;
            for(int p2 = 0; p2<(1<<n); p2++)
            {
                sum += a[i-1][p2] * d[p2][p1];
            }
            a[i][p1] = sum;
            //cout<<a[i][p1]<<" ";
            if(i==m+1)
                ma=max(ma, a[i][p1]);
        }
        //cout<<endl;
    }
    //cout<<endl;
    cout<<ma;
}
