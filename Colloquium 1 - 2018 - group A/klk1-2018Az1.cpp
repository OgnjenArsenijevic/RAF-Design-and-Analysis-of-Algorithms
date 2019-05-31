///Kolokvijum 1 - 2017/18 grupa A z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlog n)
///Additional Space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Line
{
    int x1,x2,y;
    Line(int yy,int xx1,int xx2): y(yy), x1(xx1), x2(xx2){}
    void print()
    {
        cout<<y<<" "<<x1<<" "<<x2<<"\n";
    }
}LINE;

int n,ans;
vector<LINE> v;

bool compare(LINE a, LINE b)
{
    if(a.y<b.y)
        return true;
    if(a.y>b.y)
        return false;
    if(a.x2<b.x2)
        return true;
    if(a.x2>b.x2)
        return false;
    if(a.x1<=b.x1)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(Line(a,b,c));
    }
    sort(v.begin(),v.end(),compare);
    if(n==0)
    {
        cout<<"0\n";
        return 0;
    }
    ans=1;
    int currY=v[0].y, currEnd=v[0].x2;
    for(int i=1;i<n;i++)
    {
        if(v[i].y==currY)
        {
            if(v[i].x1>currEnd)
                ans++;
            currEnd=v[i].x2;
        }
        else
        {
            currY=v[i].y;
            ans++;
            currEnd=v[i].x2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
