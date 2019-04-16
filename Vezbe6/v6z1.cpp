///v6z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlog n)
///Additional space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int solve(vector<int> v, int l, int r)
{
    if(l==r)
        return v[l];
    int mid=(l+r)/2;
    int left=solve(v,l,mid);
    int right=solve(v,mid+1,r);
    int lMax=v[mid],sum=v[mid];
    for(int i=mid-1;i>=l;i--)
    {
        sum+=v[i];
        lMax=max(lMax,sum);
    }
    int rMax=v[mid+1];
    sum=v[mid+1];
    for(int i=mid+2;i<=r;i++)
    {
        sum+=v[i];
        rMax=max(rMax,sum);
    }
    return max(max(left,right),lMax+rMax);
}

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
    cout<<solve(v,0,n-1);
    return 0;
}
