///v1z7
///Author: Ognjen Arsenijevic
///Time Complexity O(n)
#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> v;
vector<int> flags;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
        flags.push_back(0);
    }
    int ans=0,curr=0;
    for(int i=0;i<n;i++)
    {
        if(curr&1)
        {
            if(v[i]==0) v[i]=1;
            else v[i]=0;
        }
        if(v[i]==0)
        {
            ans++;
            curr++;
            if(i+k-1<n)
                flags[i+k-1]=1;
            else
            {
                cout<<-1;
                return 0;
            }
        }
        if(flags[i]) curr--;
    }
    cout<<ans;
    return 0;
}
