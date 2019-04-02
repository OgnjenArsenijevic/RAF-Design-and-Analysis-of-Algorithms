///v1z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,x;
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v.push_back(make_pair(0,in));
    }
    for(int i=0;i<n;i++)
        cin>>v[i].first;
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second>=x)
        {
            ans+=(x*v[i].first);
            cout<<ans<<"\n";
            return 0;
        }
        else
        {
            ans+=(v[i].second*v[i].first);
            x-=v[i].second;
        }
    }
    cout<<"not enough milk";
    return 0;
}
