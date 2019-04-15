///v4z5
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^3)
///Additional space: O(n^2)
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n,dp[1005][1005];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    for(int i=0;i<n;i++)
        dp[i][i]=v[i];
    for(int len=1;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {
            int j=i+len;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]-dp[k+1][j]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
