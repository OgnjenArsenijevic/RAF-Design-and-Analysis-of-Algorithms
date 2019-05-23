///v7z5
///Author: Ognjen Arsenijevic
#include <iostream>

using namespace std;

int n,arr[1005];

void generateAllPermutations(int currNum)
{
    if(currNum==n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<currNum;j++)
        {
            if(arr[j]==i+1)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            arr[currNum]=i+1;
            generateAllPermutations(currNum+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    generateAllPermutations(0);
    return 0;
}
