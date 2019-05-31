///v7z6
///Author: Ognjen Arsenijevic
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string num;
vector<string> v;
char arr[105];

void generateAll(int currIdx)
{
    if(currIdx==num.size())
    {
        for(int i=0;i<num.size();i++)
            cout<<arr[i];
        cout<<"\n";
        return;
    }
    for(int i=0;i<v[num[currIdx]-'0'].size();i++)
    {
        arr[currIdx]=v[num[currIdx]-'0'][i];
        generateAll(currIdx+1);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    v.push_back("");
    v.push_back("");
    v.push_back("abc");
    v.push_back("def");
    v.push_back("ghi");
    v.push_back("jkl");
    v.push_back("mno");
    v.push_back("pqrs");
    v.push_back("tuv");
    v.push_back("wxyz");
    cin>>num;
    generateAll(0);
    return 0;
}
