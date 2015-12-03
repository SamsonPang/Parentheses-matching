/**
描述:
现在，有一行括号序列，请你检查这行括号是否配对。
输入
第一行输入一个数N（0<N<=100）,表示有N组测试数据。
后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），测试数据组数少于5组。
PS:数据保证S中只含有"[","]","(",")"四种字符

输出
每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No
样例输入

3
[(])
(])
([[]()])

样例输出
No
No
Yes
**/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isMatch(char a,char b);

int main(){
	unsigned int N;
	cin >> N;
	if((0>=N) && (N>100)) return 0;

	vector<string> vs;
	string st;

	//accept the input
	for(vector<string>::size_type ix = 0; ix < N; ix++){
		cin >> st;
		vs.push_back(st);
	}

	//jugde and output
	for(vector<string>::size_type ix = 0; ix < vs.size(); ix++){
		st = vs[ix];

		if(ix != 0){
			cout << endl;
		}

		if((st.size() == 0) || (st.size() >= 10000) || (st.size()%2 != 0)) {
			cout << "No";
		} else {
			stack<char> myStack;

			for(string::size_type ix = 0; ix < st.size(); ix++) {
				if(!myStack.empty()) {
					if(isMatch(myStack.top(),st[ix])) {
						myStack.pop();
					} else {
						myStack.push(st[ix]);
					}
				} else {
					myStack.push(st[ix]);
				}
			}
			if (!myStack.empty()){
				cout << "No";
			} else {
				cout << "Yes";
			}
		}
	}

	//system("pause");
	return 0;
}

bool isMatch(char a, char b){
	if((a == '(') && b == ')') return true;
	if((a == '[') && b == ']') return true;
	return false;
}
