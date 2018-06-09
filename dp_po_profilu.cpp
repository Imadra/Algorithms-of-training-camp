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
int d[1509][1509], n, m, sum, a[1509][1509];
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
void go(int p, int profile, int len)
{
    //cout<<p<<" "<<profile<<" "<<len<<" ";
    //cout<<bit(p, len)<<endl;
    // n - из условия задачи
    // profile - текущий профиль
    // len - длина profile
    if (len == n)
    {
        // как только profile получился длины n, выходим
        d[p][profile] = 1;
        return;
    }
    if (bit(p, len) == 0)
    {
        // текущая ячейка в p (с номером len + 1) не занята
        go(p, profile + (1 << len), len + 1);
        // положили горизонтальную доминошку
        if (len < n - 1)
            if (bit(p, len + 1) == 0)
            {
                // не занята еще и следующая ячейка
                go(p, profile , len + 2);
                // положили вертикальную доминошку
            }
    }
    else
    {
        go(p, profile, len + 1);
        // текущая ячейка занята, ничего положить не можем
    }
}
int main()
{
    cin >> n >> m;
    for (int p = 0; p < (1<<n); p++)
        go(p, 0, 0); // запускать надо именно с такими параметрами
    //cout<<bit(0, 1)<<endl;
    /*for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }*/
    a[1][0] = 1;
    for(int p2=1;p2<(1<<n);p2++)
        a[1][p2]=0;
    for(int i=2;i<=m+1;i++)
    {
        for(int p1=0;p1<(1<<n);p1++)
        {
            sum=0;
            for(int p2 = 0;p2<(1<<n);p2++)
            {
                sum += a[i-1][p2] * d[p2][p1];
            }
            a[i][p1] = sum;
            //cout<<a[i][p1]<<" ";
        }
        //cout<<endl;
    }
    cout<<a[m+1][0];
}
