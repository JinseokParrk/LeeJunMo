/*
Ǯ�̿� �ɸ� �ð� : 20��
���⵵ ��� : N
���� �ð� : 336 ms
�޸� : 2048 KB
���� ���� : ���ͷ� Ǯ� �ٽ� Ǯ����ҵ�.
Ǯ�� ��� : 
*/

#include<iostream>
#include <sstream>
#include<vector>
using namespace std;

/*
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

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






