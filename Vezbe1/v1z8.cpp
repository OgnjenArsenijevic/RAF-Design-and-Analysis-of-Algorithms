///v1z8
///Author: Ognjen Arsenijevic
///Time Complexity O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int ans[100005];

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
    sort(v.begin(),v.end());
    int currWaitTime=0,st=0,en=n-1;
    for(int i=0;i<n;i++)
    {
        if(v[i]>=currWaitTime)
        {
            ans[st++]=v[i];
            currWaitTime+=v[i];
        }
        else
            ans[en--]=v[i];
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
