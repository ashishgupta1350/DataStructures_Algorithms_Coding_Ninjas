#include<iostream>
#include<stack>
using namespace std;

bool balancedBracket(string ch)
{
	stack<char> s;
	for(int i=0;i<ch.length();i++)
	{
		if(s.size()==0 && (ch[i]==')'||ch[i]=='}'||ch[i]==']'))
		{
//			cout<<"returning from 1st bracket "<<endl;
//			cout<<"stack size: "<<s.size()<<endl;
			return false;
		}
		
		if(ch[i]=='(' || ch[i]=='[' || ch[i]=='{')
		{
//			cout<<"Pushing  "<<ch[i]<<endl;
			
			s.push(ch[i]);
//			cout<<"stack size: "<<s.size()<<endl;
		}
		
		if(ch[i]==')'&& s.top()=='(')
		{
//			cout<<"Popped "<<ch[i]<<endl;
			
			s.pop();
//			cout<<"stack size: "<<s.size()<<endl;
		}
		if(ch[i]==']'&& s.top()=='[')
		{
//			cout<<"Popped "<<ch[i]<<endl;
			
			s.pop();
//			cout<<"stack size: "<<s.size()<<endl;
		}
		if(ch[i]=='}'&& s.top()=='{')
		{
//			cout<<"Popped "<<ch[i]<<endl;
			s.pop();
//			cout<<"stack size: "<<s.size()<<endl;
		}
	}
	return s.size()==0;
}
int main()
{
	string ch;
	getline(cin,ch);
	
	bool ans=balancedBracket(ch);
	if(ans==1) 
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
}
