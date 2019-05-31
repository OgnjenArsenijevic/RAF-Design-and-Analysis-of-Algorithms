///v3z6
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^3)
///Additional space: O(n^2)
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

int n,dp[1005][1005];
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for(int i=0;i<n-1;i++)
        dp[i][i+1]=v[i].first*v[i].second*v[i+1].second;
    for(int len=2;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {
            int j=i+len;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+v[i].first*v[k].second*v[j].second);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
