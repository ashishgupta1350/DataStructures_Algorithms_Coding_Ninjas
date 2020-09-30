#include<iostream>
#include<stack>
using namespace std;

bool Duplicate(string ch)
{
	stack<char> s;
	for(int i=0;i<ch.size();i++)
	{
		if(ch[i]!=')')
		{
			s.push(ch[i]);
		}
		if(ch[i]==')')
		{
			if(s.top()=='(')
			{
				return true;
			}
			while(s.top()!='(')
			{
				s.pop();
			}
			s.pop();
		}
		
	}
	return false;
}
int main()
{
//	char ch[101];
	string ch;
	getline(cin,ch);
	bool ans=Duplicate(ch);
	if(ans==1)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
}
