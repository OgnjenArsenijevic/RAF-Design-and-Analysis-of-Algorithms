///v3z5
///Author: Ognjen Arsenijevic
///Time Complexity: O(nw)
///Additional space: O(w)
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n,w,dp[1005];
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        int ww,cc;
        cin>>ww>>cc;
        v.push_back(make_pair(ww,cc));
    }
    for(int i=1;i<=w;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[j].first<=i)
                dp[i]=max(dp[i],dp[i-v[j].first]+v[j].second);
        }
    }
    cout<<dp[w];
    return 0;
}
