///v5z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(nm)
///Additional space: O(m)
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n,m,dp[1005];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    dp[0]=0;
    for(int i=1;i<=m;i++)
        dp[i]=INT_MAX-1; //-1 da mi ne bi overflow-ovao posle
    for(int j=0;j<n;j++)
    {
        for(int i=m;i>0;i--)
        {
            if(v[j]>i)
                break;
            else
                dp[i]=min(dp[i],dp[i-v[j]]+1);
        }
    }
    cout<<(dp[m]==INT_MAX-1 ? -1 : dp[m]);
    return 0;
}
