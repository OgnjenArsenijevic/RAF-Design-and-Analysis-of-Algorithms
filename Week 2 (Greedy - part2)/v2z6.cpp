///v2z6
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        v.push_back(make_pair(r,l));
    }
    sort(v.begin(),v.end());
    int ans=1,curr=v[0].first;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].second>curr)
        {
            curr=v[i].first;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
