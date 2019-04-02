///v1z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,w;
vector<pair<double,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v.push_back(make_pair(0,in));
    }
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v[i].first=((double)in)/v[i].second;
    }
    sort(v.begin(),v.end());
    double ww=(double)w;
    double ans=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i].second>=w)
        {
            ans+=(w*v[i].first);
            cout<<ans<<"\n";
            return 0;
        }
        else
        {
            w-=v[i].second;
            ans+=(v[i].second*v[i].first);
        }
    }
    cout<<"invalid testcase";
    return 0;
}
