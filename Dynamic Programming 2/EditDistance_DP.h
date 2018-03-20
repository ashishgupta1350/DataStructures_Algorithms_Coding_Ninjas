#include<iostream>
using namespace std;
#include<string>

int editDistance(string s,string t)
{
    ///create a dynamic array
    int sizeY=s.size()+1;
  int sizeX=t.size()+1;
  int m=sizeY;
  int n=sizeX;
  /// initializing a 2D array
    int **ans = new int*[sizeY];
	for(int i = 0; i < sizeY; ++i) {
   	 ans[i] = new int[sizeX];
	}

    for(int i=0;i<m;i++)
    {
        ans[i][0]=i;
    }
    for(int i=0;i<n;i++)
    {
        ans[0][i]=i;
    }

    ///s[row-1] , t[col-1] is the correct indexing
    for(int col=1;col<=n;col++)
    {
        for(int row=1;row<=m;row++){

             if(s[row-1]==t[col-1])
             {
                 ans[row][col]=ans[row-1][col-1];
             }
             else{

                ans[row][col]=1+min(ans[row-1][col-1],min(ans[row-1][col],ans[row][col-1]));
             }
        }
    }
    return ans[m][n];
}
