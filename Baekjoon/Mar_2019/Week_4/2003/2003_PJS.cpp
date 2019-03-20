/*
Ǯ�̿� �ɸ� �ð� : 15��
���⵵ ��� : O(N����)
���� �ð� : 32 ms
�޸� : 1988 KB
���� ���� : X
Ǯ�� ��� : �迭�� 1���� N���� ���� �����Ѵ�.
			-> ���� for���� ����Ͽ�, 1���� 1�� �ε��� �����ϸ� �����ش�. ������ 2���� ��, ������ 3���� ��...
			-> ���Ѱ��� M�� ������ allCase 1���ϰ�, ���Ѱ��� M�� ������ for�� ����.
*/

//N(1��N��10,000), M(1��M��300,000,000)

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

	int allCase = 0;  // ��� ����� ��	
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
