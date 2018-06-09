#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
string t, ss, h;
long long n, l, r, sum;
void z_f(string s)
{
    vector<long long> d(n);
    for(int i=0;i<n;i++)
    {
        if(i<=r)
        {
            d[i]=min(d[l+r-i], r-i);
        }
        while(s[i+d[i]]==s[i-d[i]] && i+d[i]<n && i-d[i]>=0)
            d[i]++;
        if(i+d[i]-1>r)
            r=i+d[i]-1, l=i-d[i]+1;
        //cout<<i<<" "<<d[i]<<" "<<l<<" "<<r<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<d[i]-1<<" ";
        sum+=(d[i]-1);
    }
    cout<<endl;
}
int main()
{
    //ifstream cin("numbers.in");
    //ofstream cout("numbers.out");
    cin>>t;
    n=t.length();
    z_f(t);
    cout<<sum;
}
