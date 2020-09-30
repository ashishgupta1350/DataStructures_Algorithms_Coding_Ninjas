#include<iostream>
#include<stack>
using namespace std;

int* ngeor(int n,int *ar,int *ans)
{
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(s.size()>0&&ar[i]>ar[s.top()])
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
	ans=ngeor(n,ar,ans);
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<endl;
	}
}
