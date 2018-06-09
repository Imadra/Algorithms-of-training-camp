#include <vector>
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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#define inf 1000*1000*1000
#define ff first
#define ss second
#define mp make_pair
using namespace std;
double l = 1, r = 100000, EPS = 3;
int f(double x)
{
    return abs(1000-x);
}
int main()
{
    cin>>l>>r;
    while(r - l > 3)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if(f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    cout<<l<<"-->"<<r;
}
