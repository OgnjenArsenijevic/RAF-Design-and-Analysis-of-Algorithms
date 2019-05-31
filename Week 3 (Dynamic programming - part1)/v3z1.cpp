///v3z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int dp[3];

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
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);
    for(int i=2;i<v.size();i++)
    {
        dp[2]=max(dp[0]+v[i],dp[1]);
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    cout<<dp[2];
    return 0;
}
