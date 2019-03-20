/*
풀이에 걸린 시간 : 15분
복잡도 계산 : O(N제곱)
수행 시간 : 32 ms
메모리 : 1988 KB
오답 이유 : X
풀이 방법 : 배열에 1부터 N까지 값을 저장한다.
			-> 이중 for문을 사용하여, 1부터 1씩 인덱스 증가하며 더해준다. 다음은 2부터 쭉, 다음은 3부터 쭉...
			-> 더한값이 M과 같으면 allCase 1더하고, 더한값이 M을 넘으면 for문 종료.
*/

//N(1≤N≤10,000), M(1≤M≤300,000,000)

#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M;
	int i, j;
	cin >> N >> M;
	vector<int> A(N+1, 0);
	for ( i = 1; i <= N; ++i) {
		cin >> A[i];
	}

	int allCase = 0;  // 모든 경우의 수	
	for (i = 1; i <= N; ++i) {
		int sum = 0;
		for (j = 0; j <= N-i; ++j) {
			sum += A[i + j];  // A[1+0] A[1+1] A[1+2] ... A[2+0] A[2+1]... A[N+0]... A[N+N-N]
			if (sum == M) {
				allCase++;
				break;
			}
			if (sum > M) {
				break;
			}
		}
	}
	cout << allCase << endl;
	return 0;
}
