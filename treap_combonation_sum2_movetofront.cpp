#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<utility>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#define inf 1000*1000*1000
#define f first
#define s seconds
using namespace std;
int n, m, x, y;
struct node
{
    node* l;
    node* r;
    int y, val, sz;
    long long sum, key, mi;
    node()
    {
        l = r = 0;
    }
};
typedef node* pnode;
pnode L, R, M, _x, root;
int get(pnode v)
{
    if(!v)
        return 0;
    return v->sz;
}
long long sum2(pnode v)
{
    return !v ? 0 : v->sum;
}
long long min2(pnode v)
{
    return !v ? inf : v->mi;
}
void calc(pnode v)
{
    if(!v)
        return;
    v->sz = get(v->l) + get(v->r) + 1;
    v->sum = sum2(v->l) + sum2(v->r) + v->val;
    if(min2(v -> l) < v -> mi)
        v -> mi = min2(v -> l);
    if(min2(v -> r) < v -> mi)
        v -> mi = min2(v -> r);
}
int key(pnode v)
{
    return get(v->l) + 1;
}
void split(pnode v, int x, pnode &l, pnode &r)
{
    if(!v)
    {
        l = r = 0;
        return;
    }
    if(key(v) < x)
    {
        l = v;
        split(v->r, x - key(v), v->r, r);
    }
    else
    {
        r = v;
        split(v->l, x, l, v->l);
    }
    calc(l);
    calc(r);
    /*for(int i=1;i<=n;i++)
    {
        calc(l+1);
        calc(r+1);
        do
        {
            for(int j=1;j<=n;j++)
            {
                cout<<b[i][j];
            }
        }
        while(next_permutation(a+1, a+n+1))
    }*/
}
pnode merge(pnode a, pnode b)
{
    if(!a || !b)
        return !a ? b : a;
    pnode res;
    if(a->y > b->y)
    {
        res = a;
        res->r = merge (a->r, b);
    }
    else
    {
        res = b;
        res->l = merge (a, b->l);
    }
    calc(res);
    return res;
}
/*void del(int x)
{
    if(!_find(x))
        return;
    split(root, x, L, R);
    split(R, x + 1, M, R);
    root = merge(L, R);
    calc(root);
}*/
void add(int x)
{
    //cout<<"zahod v merge noda  s priorom ";
    _x = new node;
    _x -> val = x;
    _x -> y = rand()<<16|rand();
    _x -> sz = 1;
    _x -> sum = x;
    _x -> mi = x;
    root = merge(root, _x);
    //cout<<"vihod i prior roota = "<<root->y<<endl;
}
char ch;
int main()
{
    srand(time(NULL));
    L = new node;
    M = new node;
    R = new node;
    root = new node;
    root = NULL;
    cin>>m;
    /*for(int i=0; i<n; i++)
    {
        add(i+1);
    }*/
    for(int i=0; i<m; i++)
    {
        cin>>ch;
        if(ch == 'Q')
        {
            long long ret = 0;
            scanf("%d%d", &x, &y);
            split(root,y+1,L,R);
            split(L,x,L,M);
            ret = sum2(M);
            root = merge(merge(L, M), R);
            cout<<ret<<endl;
        }
        if(ch == 'M')
        {
            long long ret = 0;
            scanf("%d%d", &x, &y);
            split(root,y+1,L,R);
            split(L,x,L,M);
            ret = min2(M);
            root = merge(merge(L, M), R);
            cout<<ret<<endl;
        }
        if(ch == 'A')
        {
            scanf("%d%d", &x);
            add(x);
        }
        //if(ch == 'D')
        //{
        //    scanf("%d%d", &x);
        //    del(x);
        //}
    }
}
//100
//A 100
//A 4
//A 150
//Q 1 3
//M 1 3
