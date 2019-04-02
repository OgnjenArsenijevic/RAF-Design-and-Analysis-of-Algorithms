///v1z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n,a,b;
vector<pair<int,int> > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(b,a)); ///ubacujemo obrnut interval jer hocemo da sortiramo po kraju
    }
    sort(v.begin(),v.end());
    if(v.size()==0)
    {
        cout<<0;
        return 0;
    }
    int ans=1,currEnd=v[0].first;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].second>=currEnd)
        {
            ans++;
            currEnd=v[i].first;
        }
    }
    cout<<ans;
    return 0;
}
