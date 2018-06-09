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
        int k=(i>r ? 0 : min(d[l+r-i], r-i))+1;
        while(s[i+k]==s[i-k] && i+k<n && i-k>=0)
            ++k;
        if(i+k>r)
            r=i+k, l=i-k;
        d[i]=k;
        //cout<<i<<" "<<d[i]<<" "<<l<<" "<<r<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<d[i]-1<<" ";
        //sum+=(d[i]-1);
    }
    cout<<endl;
}
void z_f2(string s)
{
    vector<long long> d2(n);
    l=0, r=-1;
    for(int i=0;i<n;i++)
    {
        int k=(i>r ? 0 : min(d2[l+r-i+1], r-i+1))+1;
        while(s[i+k-1]==s[i-k] && i+k-1<n && i-k>=0)
            ++k;
        if(i+k>r)
            r=i+k, l=i-k;
        d2[i]=k;
        //cout<<i<<" "<<d2[i]<<" "<<l<<" "<<r<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<d2[i]<<" ";
        //sum+=d2[i];
    }
}
int main()
{
    //ifstream cin("numbers.in");
    //ofstream cout("numbers.out");
    cin>>t;
    n=t.length();
    z_f(t);
    //cout<<endl;
    l=0, r=0;
    z_f2(t);
    //cout<<endl;
    //cout<<sum;
}

