#include<iostream>
#include<stack>
using namespace std;

int* ngeol(int n,int *ar,int *ans)
{
	ans[0]=-1;
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(s.size()>0 && ar[i]>ar[s.top()])
		{
			s.pop();
		}
		
		if(s.size()==0)
		{
			ans[i]=-1;
		}
		else
		{
			ans[i]=ar[s.top()];
		}
		s.push(i);
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
