#include<iostream>
#include<stack>
using namespace std;

int* ngeor(int n,int *ar,int *ans)
{
	stack<int>s;
	ans[n-1]=-1;
	s.push(ar[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		while(s.size()>0 && s.top()<=ar[i])
		{
			s.pop();
		}
		if(s.size()==0)
		{
			ans[i]=-1;
		}
		else 
		{
			ans[i]=s.top();
		}
		s.push(ar[i]);
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
	ans=ngeor(n,ar,ans);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
}
