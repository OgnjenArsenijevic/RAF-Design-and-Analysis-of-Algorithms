///v2z8
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int n,d,w;
vector<pair<double,double> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>d>>w;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        double dis=sqrt(r*r-(double)w*w/4.0);
        v.push_back(make_pair(l-dis,l+dis));
    }
    sort(v.begin(),v.end());
    double nextToCover=0.0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        double currL=v[i].first, currR=v[i].second;
        if(currL>nextToCover)
        {
            cout<<"invalid testcase";
            return 0;
        }
        while(v[i].first<=nextToCover)
        {
            if(v[i].second>currR)
                currR=v[i].second;
            i++;
        }
        i--;
        ans++;
        nextToCover=currR;
        if(nextToCover>d)
            break;
    }
    cout<<ans;
    return 0;
}
