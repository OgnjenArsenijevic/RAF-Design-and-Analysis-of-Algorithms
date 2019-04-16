///v5z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^2)
///Additional space: O(n^2)
#include <iostream>
#include <vector>

using namespace std;

int n,dp[1005][1005],prefSum[1005];
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
    prefSum[0]=v[0];
    for(int i=1;i<n;i++)
        prefSum[i]=prefSum[i-1]+v[i];
    for(int i=0;i<n;i++)
        dp[i][i]=v[i];
    for(int len=1;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {
            int j=i+len;
            dp[i][j]=max(v[i]+prefSum[j]-prefSum[i]-dp[i+1][j],v[j]+prefSum[j-1]-(i>0 ? prefSum[i-1] : 0)-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
