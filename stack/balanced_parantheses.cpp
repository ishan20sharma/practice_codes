#include<iostream>
#include<stack>

using namespace std;

bool checkBalancedParantheses(string &paren) {
	stack<char> st;
	
	/* Traverse the whole string */
	for(int i=0; i < paren.length(); ++i) {
		/* If the character is an opening parenthesis push it into the stack */
		if(paren[i] == '(' || paren[i] == '{' || paren[i] == '[')
			st.push(paren[i]);

		/* If the character is a closing parenthesis match it against the top of the stack */
		else if(paren[i] == ')') {
			if(!st.empty()) {
				if(st.top() ==	'(') {
					st.pop();
				}
				else
					return false;
			}
			else
				return false;
		}
		else if(paren[i] == '}') {
			if(!st.empty()) {
                                if(st.top() ==  '{') {
                                        st.pop();
                                }
                                else
                                        return false;
                        }
                        else
                                return false;

		}
		else if(paren[i] == ']') {
			if(!st.empty()) {
                                if(st.top() ==  '[') {
                                        st.pop();
                                }
                                else
                                        return false;
                        }
                        else
                                return false;
			
		}

	}
	/* If after traversal, the stack is not empty then return false */
	if(!st.empty())
		return false;
	else
		return true;
	
}

int main() {
	string paren = "[(])";

	/* Test cases:
		Input : [()]{}{[()()]()}
		Output: True

		Input: [(])
		Output: False
	*/
	
	if(checkBalancedParantheses(paren))
		cout << "Parantheses is balanced" << endl;
	else
		cout << "Parantheses is not balanced" << endl;

	return 0;
}
