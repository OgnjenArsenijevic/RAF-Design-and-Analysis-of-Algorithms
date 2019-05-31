///v2z9
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n,dif,ans,mini;
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int gas,cost;
        cin>>gas>>cost;
        v.push_back(make_pair(gas,cost));
    }
    for(int i=0;i<n;i++)
    {
        dif+=v[i].first-v[i].second;
        if(dif<mini)
        {
            mini=dif;
            ans=i+1;
        }
    }
    cout<<(dif<0 ? -1 : ans);
    return 0;
}
