///v3z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^2)
///Additional space: O(n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n,dp[1005],idx[1005];
vector<int> v;
vector<int> ans;

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
    memset(idx,-1,sizeof(idx));
    dp[0]=1;
    for(int i=1;i<v.size();i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i] && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                idx[i]=j;
            }
        }
    }
    cout<<*max_element(dp,dp+v.size())<<"\n";
    int saveIdx;
    for(int i=0;i<v.size();i++)
    {
        if(dp[i]==(*max_element(dp,dp+v.size())))
        {
            saveIdx=i;
            break;
        }
    }
    while(true)
    {
        if(saveIdx==-1)
            break;
        ans.push_back(v[saveIdx]);
        saveIdx=idx[saveIdx];
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
