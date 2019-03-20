/*
풀이에 걸린 시간 : 5분
복잡도 계산 : N
수행 시간 : 0ms
메모리 : 1988 KB
오답 이유 :
풀이 방법 : [Memoization] int형으로 풀었는데 수가 커저셔 long long으로 품.
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