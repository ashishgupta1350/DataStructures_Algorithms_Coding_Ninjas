#include<iostream>
#include<stack>
using namespace std;

int largestAreaUnderHistogram(int n,int *ar,int *lb,int *rb)
{
	stack<int> s;
	rb[n-1]=n;
	s.push(n-1);
	for(int i=n-2;i>=0;i--)
	{
		while(s.size()>0 && ar[i]<=ar[s.top()])
		{
			s.pop();
		}
		if(s.size()==0)
		{
			rb[i]=n;
		}
		else
		{
			rb[i]=s.top();
		}
		s.push(i);
	}
	while(s.size()!=0)
	{
		s.pop();
	}
	
	lb[0]=-1;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(s.size()>0 && ar[i]<=ar[s.top()])
		{
			s.pop();
		}
		if(s.size()==0)
		{
			lb[i]=-1;
		}
		else
		{
			lb[i]=s.top();
		}
		s.push(i);
	}
	int maxArea=-1;
	
	for(int i=0;i<n;i++)
	{
		int width=rb[i]-lb[i]-1;
		int area=ar[i]*width;
		if(area>maxArea)
		{
			maxArea=area;
		}
	}
	cout<<maxArea<<endl;
	
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
	int *lb=new int[n]; //stores left smallest element
	int *rb=new int[n]; //stores right smallest element
	largestAreaUnderHistogram(n,ar,lb,rb);
	
}
