#include<iostream>
#include<stack>
using namespace std;

int* ngeol(int n,int* ar,int *ans)
{
	ans[0]=-1;
	stack<int> s;
	s.push(n-1);
	for(int i=n-2;i>=0;i--)
	{
		while(s.size()>0 && ar[i]>ar[s.top()])
		{
			ans[s.top()]=ar[i];
			s.pop();
		}
		s.push(i);
	}
	while(s.size()!=0)
	{
		ans[s.top()]=-1;
		s.pop();
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int *ar=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	int *ans=new int[n];
	ans=ngeol(n,ar,ans);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
}
