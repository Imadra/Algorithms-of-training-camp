#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 100000000;
int n, cnt;
bitset<MAXN> prime;
int main ()
{
    //freopen ("primes.in", "r", stdin);
    //freopen ("primes.out", "w", stdout);
    cin>>n;
    prime[2] = 1;
    for(int i=3;i<=n;i+=2)
        prime[i] = 1;
    for (int i = 3; i * i <= n; i += 2)
        if (prime[ i ])
                for (int j = i * 1ll * i; j <= n; j += 2 * i)
                    prime[ j ] = 0;
    cout<<2<<" ";
    cnt=1;
    for(int i = 3; i <= n; i += 2)
    {
        if(prime[i])
            cout<<i<<" ", cnt++;
    }
    cout<<endl<<cnt;
}
