///v1z11
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn+mlogm)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dragons;
vector<int> knights;
int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        dragons.push_back(in);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int in;
        cin>>in;
        knights.push_back(in);
    }
    sort(dragons.begin(),dragons.end());
    sort(knights.begin(),knights.end());
    int idx=0,ans=0;
    for(int i=0;i<dragons.size();i++)
    {
        bool flag=false;
        while(idx<knights.size())
        {
            if(knights[idx]>=dragons[i])
            {
                ans+=knights[idx++];
                flag=true;
                break;
            }
            else
                idx++;
        }
        if(!flag)
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
