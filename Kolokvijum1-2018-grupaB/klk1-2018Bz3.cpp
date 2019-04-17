///Kolokvijum 1 - 2017/18 grupa B z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlog n)
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int solveA(vector<int> v, int l, int r)
{
    if(l==r)
        return 1;
    int mid=(l+r)/2;
    int left=solveA(v,l,mid);
    int right=solveA(v,mid+1,r);
    int cnt=1;
    for(int i=mid-1;i>=l;i--)
    {
        if(v[i]<v[i+1])
            cnt++;
        else
            break;
    }
    for(int i=mid+1;i<=r;i++)
    {
        if(v[i]>v[i-1])
            cnt++;
        else
            break;
    }
    return max(max(left,right),cnt);
}

int solveB(vector<int> v, int l, int r)
{
    if(l==r)
        return 1;
    int mid=(l+r)/2;
    int left=solveB(v,l,mid);
    int right=solveB(v,mid+1,r);
    int cntL=0,cntR=0;
    for(int i=mid;i>=l;i--)
    {
        if(v[i]<v[i+1])
            cntL++;
        else
            break;
    }
    for(int i=mid+1;i<=r;i++)
    {
        if(v[i]>v[i-1])
            cntR++;
        else
            break;
    }
    return left+right+cntL*cntR;
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
    cout<<solveA(v,0,n-1)<<"\n"<<solveB(v,0,n-1);
    return 0;
}
