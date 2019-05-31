///v7z4
///Author: Ognjen Arsenijevic
#include <iostream>

using namespace std;

int n;
bool used[1005];

void generateAllCombinations(int currNum)
{
    if(currNum==n)
    {
        bool flag=false;
        cout<<"{";
        for(int i=0;i<n;i++)
        {
            if(used[i])
            {
                if(flag) cout<<", ";
                cout<<i+1;
                flag=true;
            }
        }
        cout<<"}\n";
        return;
    }
    used[currNum]=true;
    generateAllCombinations(currNum+1);
    used[currNum]=false;
    generateAllCombinations(currNum+1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    generateAllCombinations(0);
    return 0;
}
