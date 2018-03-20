#include<iostream>
using namespace std;
void printstars(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<"* "; }
}
void specialstarseq(int n){

    if(n%2==1)
        printstars(n/2+1);
    else{
        printstars(n/2);
    }
}
void printspaces(int n){

    for(int i=1;i<=n;i++)
    {
        cout<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int spaces;
    spaces=2*n-4;
    cout<<" Spaces = "<<spaces<<endl;
    for(int i=1;i<n;i++)
    {
        if(i%2==0){printspaces(1);}

        specialstarseq(i);

        printspaces(spaces);
        spaces-=2;

        specialstarseq(i);

        cout<<endl;
    }
    spaces=0;
    printstars(n);
    cout<<endl;
    for(int i=n-1;i>=1;i--)
    {
       if(i%2==0){printspaces(1);}

        specialstarseq(i);

        printspaces(spaces);
        spaces+=2;

        specialstarseq(i);

        cout<<endl;



    }

    return 0;
}
/*3
*     *
 *   *
* * *
 * *
*   *
*/
