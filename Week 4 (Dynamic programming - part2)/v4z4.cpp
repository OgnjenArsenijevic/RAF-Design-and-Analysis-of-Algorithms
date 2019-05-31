///v4z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(nm)
///Additional space: O(nm)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n,m,dp[1005][1005];
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    v.push_back(make_pair(0,0)); //dummy
    for(int i=0;i<m;i++)
    {
        int vv,zz;
        cin>>vv>>zz;
        v.push_back(make_pair(vv,zz));
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            dp[i][j%2]=dp[i][(j-1)%2];
            if(v[j].second<=i)
                dp[i][j%2]=max(dp[i][j%2],dp[i-v[j].second][(j-1)%2]+v[j].first);
        }
    }
    cout<<dp[n][m%2];
    return 0;
}
