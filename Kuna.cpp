#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<string.h>
using namespace std;
int n, x, k, ans, used[259], mt[259];
vector<int> g[259];
bool try_kuhn (int v)
{
    if (used[v])
        return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        while(cin>>x)
        {
            if(x == 0)
                break;
            g[i].push_back(x-1);
        }
    }
    memset(mt, 0, sizeof(mt));
    for (int v=0; v<n; ++v)
    {
        memset(used, 0, sizeof(used));
        try_kuhn (v);
    }
    for (int i=0; i<k; ++i)
        if (mt[i] != -1)
            ans++;
    cout<<ans<<endl;
    for(int i=0; i<k; i++)
        if(mt[i]!=-1)
            cout<<mt[ i ] + 1 << " " << i + 1 << endl;
}
