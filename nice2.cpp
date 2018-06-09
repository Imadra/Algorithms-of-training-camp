#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

#define one(x,i) (((x)&(1<<(i))) != 0)

const int N = 130;
const int M = 16;
int n, m;
int mm;
unsigned int d[2][1<<(M+1)];

#define mod 10000
#define add(x) (((x)>>1)|(1<<m))
#define del(x) (((x)>>1))
#define cur 1
#define old 0

void out (int mask)
{
    for (int i = 0; i <= m; i++)
        cout << one(mask,i);
}
int main ()
{
    // freopen ("nice.in", "r", stdin);
    //   freopen ("nice2.in", "w", stdout);

    cin >> n >> m;
    if (n < m)
        swap (n,m);
    mm = 1<<(m+1);
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m; j++)
        {
            for (int pr = 0; pr < mm; pr++)
            {
                if (!i && !j)
                {
                    d[cur][pr] = 1;
                    continue;
                }
                int c = one(pr,0) + one(pr,1) + one(pr,m);
                if ((c != 0 && c != 3) || j == 0)
                {
                    d[cur][pr] = d[old][add(pr)] + d[old][del(pr)];
                    while (d[cur][pr] > mod)
                        d[cur][pr] -= mod;
                }
                else
                {
                    if (c == 0)
                        d[cur][pr] = d[old][add(pr)];
                    if (c == 3)
                        d[cur][pr] = d[old][del(pr)];
                }
            }
            for (int pr = 0; pr < mm; pr++)
                d[old][pr] = d[cur][pr];
        }
    unsigned int res = 0;
    for (int i = 0; i < mm; i++)
    {
        res += d[cur][i];
        while (res > mod)
            res -= mod;
    }
    if (n == 1 && m == 1)
        res = 2;
    cout << res;
    return 0;
}
