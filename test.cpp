/**
����:
���ڣ���һ���������У����������������Ƿ���ԡ�
����
��һ������һ����N��0<N<=100��,��ʾ��N��������ݡ�
�����N����������������ݣ�ÿ���������ݶ���һ���ַ���S(S�ĳ���С��10000����S���ǿմ���������������������5�顣
PS:���ݱ�֤S��ֻ����"[","]","(",")"�����ַ�

���
ÿ���������ݵ����ռһ�У�������ַ�������������������Եģ������Yes,�������������No
��������

3
[(])
(])
([[]()])

�������
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
