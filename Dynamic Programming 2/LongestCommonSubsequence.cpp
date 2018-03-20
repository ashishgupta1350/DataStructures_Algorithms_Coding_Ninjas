#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>
int lcs_Better(string ,string, int *memo[1000]);

/*int lcs(string string1,string string2)
{
    if(string1.size()==0||string2.size()==0)
    {
        return 0;
    }
    if(string1[0]==string2[0])
    {
        return 1+lcs(string1.substr(1),string2.substr(1));
    }
    int a=lcs(string1,string2.substr(1));
    int b=lcs(string1.substr(1),string2);
    return max(a,b);


}*/

int lcs_memo(string str1,string str2)
{

    int memo[1000][1000];
    for(int i=0;i<=str1.size();i++)
    {
        for(int j=0;j<=str2.size();j++)
        {
            cout<<"here"<<endl;
            memo[i][j]=-1;

        }
    }
    cout<<"hi"<<endl;
   /// return lcs_Better(str1,str2,memo);
}
int lcs_Better(string string1,string string2,int ans[100][100])
{
    cout<<"Here"<<endl;
    int s1=string1.size();
    int s2=string2.size();
    if(s1*s2==0)
    {
        ans[s1][s2]=0;
        return 0;

    }
    if(ans[s1][s2]!=-1)
    {
        return ans[s1][s2];

    }
    if(string1[0]==string2[0])
    {
        if(ans[s1-1][s2-1]!=-1)
        {
            return 1+ans[s1-1][s2-1];

        }
        else
        {
            ans[s1-1][s2-1]=lcs_Better(string1.substr(1),string2.substr(1),ans);
            return 1+ans[s1-1][s2-1];

        }

    }
    if(ans[s1][s2-1]==-1)
        ans[s1][s2-1]=lcs_Better(string1,string2.substr(1),ans);

    if(ans[s1-1][s2]==-1)
        ans[s1-1][s2]=lcs_Better(string1.substr(1),string2,ans);

    ans[s1][s2]= max(ans[s1-1][s2],ans[s1][s2-1]);
return ans[s1][s2];


}
int main()
{
    unordered_map<string,int> myMap;
    string string1,string2;
    ///cin>>string1>>string2;

    int ans[100][100];
    for(int i=0;i<100;i++)
    {for(int j=0;j<100;j++)
    {
        ans[i][j]=-1;


    }
    }
    cout<<lcs_Better("Help","helop",ans)<<endl;
    char ch;

}
