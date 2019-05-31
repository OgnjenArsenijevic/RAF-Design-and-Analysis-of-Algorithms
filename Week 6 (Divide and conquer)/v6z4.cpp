///v6z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(max(numOfDistinctElements * log n, maxElement))
///Additional space: O(maxElement)
#include <iostream>
#include <vector>

using namespace std;

int n,arr[1005];
vector<int> v;

void solve(vector<int> v, int l, int r)
{
    if(v[l]==v[r])
    {
        arr[v[l]]+=(r-l+1);
        return;
    }
    int mid=(l+r)/2;
    solve(v,l,mid);
    solve(v,mid+1,r);
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
    solve(v,0,n-1);
    for(int i=0;i<=v[n-1];i++)
    {
        if(arr[i]>0)
            cout<<i<<" "<<arr[i]<<"\n";
    }
    return 0;
}
