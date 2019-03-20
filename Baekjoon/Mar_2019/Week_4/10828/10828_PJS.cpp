/*
풀이에 걸린 시간 : 20분
복잡도 계산 : N
수행 시간 : 336 ms
메모리 : 2048 KB
오답 이유 : 벡터로 풀어서 다시 풀어야할듯.
풀이 방법 : 
*/

#include<iostream>
#include <sstream>
#include<vector>
using namespace std;

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

string str1 = "23 259 .326 22 a 15";
string str2 = "1 263avj 3135df 3235 baij af9i39a fklk30";
stringstream ss(str1);
string k;

while (ss >> k)
cout << k << endl;

ss.clear();
ss.str(str2);
while (ss >> k)
cout << k << endl;
*/


int main() {	
	int N;
	cin >> N;
	cin.ignore();
	vector<int> stack;

	while (N--) {
		string s;
		string k[2];
		int a;
		int i = 0;
		getline(cin, s);

		stringstream ss(s);
		while (ss >> k[i]) {
			i++;
		}

		if (k[0].compare("push") == 0) {
			int num = atoi(k[1].c_str());
			//cout << num << endl;
			stack.push_back(num);
		}
		else if (k[0].compare("pop") == 0) {
			if (stack.empty()) { printf("%d\n", -1); }
			else {
				printf("%d\n", stack.back());
				stack.pop_back();
			}
		}
		else if (k[0].compare("size") == 0) {
			printf("%d\n",stack.size());
		}
		else if (k[0].compare("empty") == 0) {
			printf("%d\n", stack.empty());
		}
		else if (k[0].compare("top") == 0) {
			printf("%d\n", stack.empty() ? -1 : stack.back());
		}
	}
	
	return 0;
}






