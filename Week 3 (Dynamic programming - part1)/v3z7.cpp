///v3z7
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional space: O(n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,pref[1005];
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
    pref[0]=v[0];
    for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+v[i];
    int maxPref=pref[0],ans=pref[0];
    for(int i=1;i<n;i++)
    {
        ans=min(ans,pref[i]-maxPref);
        maxPref=max(maxPref,pref[i]);
    }
    cout<<ans;
    return 0;
}
