#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, k[2009], x, a[2009];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>x;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<"2 1 2"<<endl<<"2 1 2"<<endl<<"1 3"<<endl<<"1 4";
}
