///v1z9
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
#include <iostream>
#include <vector>

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
    int ans=n,currL=v[0],currR=v[n-1],l=0,r=n-1;
    while(l<r)
    {
        if(currL==currR)
        {
            currL=v[++l];
            currR=v[--r];
        }
        else
        {
            ans--;
            if(currL<currR)
                currL+=v[++l];
            else
                currR+=v[--r];

        }
    }
    cout<<ans;
    return 0;
}
