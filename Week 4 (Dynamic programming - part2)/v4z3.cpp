///v4z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^2)
///Additional space: O(n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,dp[10005];
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
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i] && dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
    }
    cout<<*max_element(dp,dp+n);
    return 0;
}
