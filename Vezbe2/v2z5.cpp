///v2z5
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
vector<int> v;
vector<int> dis;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++)
        dis.push_back(v[i]-v[i-1]-1);
    sort(dis.begin(),dis.end());
    int idx=0,ans=0;
    while(m>k)
    {
        ans+=dis[idx++];
        m--;
    }
    cout<<ans;
    return 0;
}
