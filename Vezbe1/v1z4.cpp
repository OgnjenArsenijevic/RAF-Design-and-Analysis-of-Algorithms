///v1z4
///Author: Ognjen Arsenijevic
///Time Complexity O(n)
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
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
    int curr=0,ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=abs(v[i]-curr);
        if(v[i]>curr)
            curr+=(v[i]-curr);
        else
            curr-=(curr-v[i]);
    }
    cout<<ans;
    return 0;
}
