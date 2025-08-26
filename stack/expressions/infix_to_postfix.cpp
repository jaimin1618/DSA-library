#include<bits/stdc++.h>
using namespace std;

// precedence
int prec(char& c) {
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	return -1;
}

string infixToPostfix(string& in) {
	stack<char> s;
	string res = "";

	for(auto el: in) {
		// simply push regular characters
		if((el >= 'a' && el <= 'z') || (el >= 'A' && el <= 'Z') || (el >= '0' && el <= '9'))
			res.push_back(el);

		// push opening ( bracket when encountered to keep track of (... expr ...)
		else if(el == '(')
			s.push(el);

		// when closing bracket is encountered - pop everything and output
		else if(el == ')') {
			while(!s.empty() && s.top() != '(') {
				res.push_back(s.top());
				s.pop();
			}

			if(!s.empty()) {
				s.pop();
			}
		}

		// finally if operator is scanned -> pop stack elements till stack operators are precedence is greater
		else {
			while(!s.empty() && prec(el) <= prec(s.top())) {
				res.push_back(s.top());
				s.pop();
			}

			s.push(el);
		}
	}

	while(!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string in = "a+b";
	cout << infixToPostfix(in) << endl; // ab+

	in = "(p+q)*(m-n)";
	cout << infixToPostfix(in) << endl; // pq+ mn- *

	in = "a+b*(c^d-e)^(f+g*h)-i";
	cout << infixToPostfix(in) << endl; // abcd^e-fgh*+^*+i-


	return 0;
}