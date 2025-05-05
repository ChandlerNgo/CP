#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
/*
这道题有用线段树做的，说明人家线段树用的就是好，没有任何办法


*/
struct node
{
    int index;
    int area;//用整数，避免误差
    bool operator<(const node &a)const
    {
        if(area==a.area)
            return index<a.index;
        return area<a.area;
    }
};
set<node>se;
set<node>::iterator it;
int L[maxn],R[maxn];
int x[maxn],y[maxn];
int Area[maxn];
int getArea(int i)
{
    int p=i,p1=L[i],p2=R[i];
    return abs((x[p1]-x[p])*(y[p2]-y[p])-(y[p1]-y[p])*(x[p2]-x[p]));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&x[0],&y[0]);
    for(int i=1;i<=n;i++)
    {scanf("%d%d",&x[i],&y[i]);
    L[i]=i-1;
    R[i]=i+1;
    }
    node node1;
    for(int i=1;i<n;i++)
    {
        node1.index=i;
        node1.area=getArea(i);
        Area[i]=getArea(i);
        se.insert(node1);
    }
    int t=n-m;
    while(t--)
    {
        it=se.begin();
        int p=(*it).index;
        se.erase(it);
        L[R[p]]=L[p];
        R[L[p]]=R[p];
        if(L[p]!=0)
        {
            node1.index=L[p];
            node1.area=Area[L[p]];
            it=se.find(node1);
            se.erase(it);

            node1.index=L[p];
            node1.area=getArea(L[p]);
            Area[L[p]]=node1.area;
            se.insert(node1);
        }
        if(R[p]!=n)
        {
             node1.index=R[p];
            node1.area=Area[R[p]];
            it=se.find(node1);
            se.erase(it);

            node1.index=R[p];
            node1.area=getArea(R[p]);
            Area[R[p]]=node1.area;
            se.insert(node1);
        }
        printf("%d\n",p);
    }
    return 0;
}