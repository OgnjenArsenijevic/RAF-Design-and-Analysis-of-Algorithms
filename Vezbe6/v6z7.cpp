///v6z7
///Author: Ognjen Arsenijevic
///Time Complexity: O(log n)
///Additional space: O(1)
#include <iostream>
#include <algorithm>

using namespace std;

int n,arr[1005],arr1[1005];

int median(int arr[], int n)
{
    if(n&1)
        return arr[n/2];
    return (arr[n/2]+arr[n/2-1])/2;
}

int solve(int arr[], int arr1[], int n)
{
    if(n==1)
        return (arr[0]+arr1[0])/2;
    if(n==2)
        return (max(arr[0],arr1[0])+min(arr[1],arr1[1]))/2;
    int m=median(arr,n);
    int m1=median(arr1,n);
    if(m==m1)
        return m;
    if(m<m1)
    {
        if(n&1)
            return solve(arr+n/2,arr1,n-n/2);
        return solve(arr+n/2-1,arr1,n-n/2+1);
    }
    if(n&1)
        return solve(arr1+n/2,arr,n-n/2);
    return solve(arr1+n/2-1,arr,n-n/2+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    cout<<solve(arr,arr1,n);
    return 0;
}
