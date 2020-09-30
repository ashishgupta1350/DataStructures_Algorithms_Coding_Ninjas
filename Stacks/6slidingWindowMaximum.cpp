#include<iostream>
#include<stack>
using namespace std;

void slidingWindowMaximum(int n,int k,int *ar,int *ans)
{
	ans[n-1]=n;
	stack<int> s;
	s.push(n-1);
	
	for(int i=n-2;i>=0;i--)
	{
		while(s.size()>0 && ar[i]>=ar[s.top()])
		{
			s.pop();
		}
		
		if(s.size()==0)
		{
			ans[i]=n;
			
		}
		else
		{
			ans[i]=s.top();
		}
		s.push(i);
	}
	int j=0;
	for(int i=0;i<=n-k;i++)
	{
		if(j<i)
		{
			j=i;
		}
		while(ans[j]<i+k)
		{
			j=ans[j];
		}
		cout<<ar[j]<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	
	int *ar=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	int *ans=new int[n];
	slidingWindowMaximum(n,k,ar,ans);
}
