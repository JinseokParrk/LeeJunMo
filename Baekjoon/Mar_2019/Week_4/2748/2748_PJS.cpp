/*
Ǯ�̿� �ɸ� �ð� : 5��
���⵵ ��� : N
���� �ð� : 0ms
�޸� : 1988 KB
���� ���� :
Ǯ�� ��� : [Memoization] int������ Ǯ���µ� ���� Ŀ���� long long���� ǰ.
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> fibo(N+1,0);

	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= N; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N] << endl;
	return 0;
}