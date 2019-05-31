///z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlog n)
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int n;
vector<pair<pair<int,int>, int> > v;
priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int> >, greater<pair<pair<int,int>, int> > > pq;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(make_pair(e,s),i));
    }
    sort(v.begin(),v.end());
    if(v[0].first.second>1)
    {
        cout<<"Ne moze\n";
        return 0;
    }
    int i;
    for(i=0;i<n && v[i].first.second==1;i++)
        pq.push(v[i]);
    ans.push_back(pq.top().second);
    pq.pop();
    for(int curr=2;curr<=n;curr++)
    {
        for(i;i<n && v[i].first.second==curr;i++)
            pq.push(v[i]);
        if(pq.top().first.second>curr || pq.top().first.first<curr)
        {
            cout<<"Ne moze\n";
            return 0;
        }
        ans.push_back(pq.top().second);
        pq.pop();
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
