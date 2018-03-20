#include <iostream>
using namespace std;

#include<stack>
bool checkRedundantBrackets(char *input) {
	// Write your code here


	stack<char> s;
 ///cout<<"In stack()"<<endl;
	int i=0;

	while(input[i]!='\0')
	{
	     cout<<"In stack()"<<endl;
	    ///cout<<s.top()<<endl;
	    if(input[i]=='('){

	        s.push(input[i]);
	        i++;
	    }
	    else if(s.empty()==false&&input[i]==')'&&s.top()=='#'&&input[i]!='\0')
	    {
	        s.pop();
	        if(s.empty()==false)
	        s.pop();
	        i++;
	    }
	    else{
                cout<<"here in bad place"<<endl;
	        s.push('#'); i++;
        cout<<s.top()<<endl;
	        while(input[i]!=')'&&input[i]!='('&&input[i]!='\0')
	        {
	            i++;
	        }


	    }
    cout<<" i is  : "<<i<<endl;
    if(s.empty()==false)
    cout<<"TOp element of stack is : "<<s.top()<<endl;

	}
	if(s.empty()) return false;
	else return true;

}

int main() {
	char a[100]="(a+(b+c))";
	cout<<"in main()"<<endl;
	if(checkRedundantBrackets(a)) cout<<"yes , it has reduntdant (bad) brackets"<<endl;
	else cout<<"The given eqn has no redundant brackets."<<endl;
	return 0;
}
