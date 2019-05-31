///v6z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlog n)
///Additional space: O(1)
///Ovo inace moze da se uradi Booyer-Moore Majority vote algotitmom u O(n)
///al radim ovako posto se trazi divide and conquer resenje
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
    if(left==right)
        return left;
    int cntl=0, cntr=0;
    for(int i=l;i<=r;i++)
    {
        if(v[i]==left)
            cntl++;
        if(v[i]==right)
            cntr++;
    }
    return (cntl>cntr ? left : right);
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
