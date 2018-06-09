#include<iostream>
#include<cmath>
#define inf 1000*1000*1000
using namespace std;
int n, a[10000009], f[10000009][20], kk[10000009], m, l, r, id[10000009][20];
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
    {
        f[i][0] = a[i];
        id[i][0] = i;
    }
    for(int k = 1; k <= 17; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            int x = i + pow(2, k - 1);
            if(f[i][k - 1] < f[x][k - 1])
            {
                f[i][k] = f[i][k-1];
                id[i][k] = id[i][k-1];
            }
            else
            {
                f[i][k] = f[x][k-1];
                id[i][k] = id[x][k-1];
            }
            if(x > n)
                f[i][k] = inf;
        }
    }
    for(int k = 0; k <= 17; k++)
    {
        cout << k << ":" << endl;
        for(int i = 1; i <= n; i++)
        {
            cout<<f[ i ][ k ]<<" ";
        }
        cout<<endl;
    }
    kk[ 1 ] = 0;
    for(int i = 2; i <= n; i++)
    {
        kk[ i ] = kk[ i / 2 ] + 1;
    }
    for(int i = 0; i <= 17; i++)
        f[ 0 ][ i ] = inf;
    cin>>m;
    for(int i = 1; i <= m; i++)
    {
        cin>>l>>r;
        int x = r - pow(2, kk[ r - l + 1 ]) + 1;
        if(f[ l ][ kk[r - l + 1] ] < f[ x ][ kk[r - l + 1] ])
        {
            cout<<f[ l ][ kk[r - l + 1] ]<<" "<< id[ l ][ kk[r - l + 1] ] << endl;
        }
        else
        {
            cout<<f[ x ][ kk[r - l + 1] ]<<" "<< id[ x ][ kk[r - l + 1] ] << endl;
        }
    }
}
