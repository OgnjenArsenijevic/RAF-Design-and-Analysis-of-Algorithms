///v1z6
///Author: Ognjen Arsenijevic
///Time Complexity O(n)
#include <iostream>
#include <vector>

using namespace std;

int n,sz;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>sz;
    for(int i=0;i<sz;i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    int cnt=0,i=0,currMax=0;
    while(currMax<n)
    {
        if(i<v.size() && v[i]<=currMax+1)
            currMax+=v[i++];
        else
        {
            currMax+=currMax+1;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
