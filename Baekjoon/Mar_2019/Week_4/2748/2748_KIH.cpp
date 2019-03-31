/*
 풀이에 걸린 시간 : 11:39
 복잡도 계산 : N
 수행 시간 : 0ms
 메모리 : 1988KB
 오답 이유 :
    long long 으로 하지 않아서 오버플로우로 에러.
 풀이 방법 :
    vector에 값을 추가하면서 n 번째 피보나치 구함
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    // 2584, 4181, 6765
    vector<long long> fibonacci = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};
    
    if (N < 18) {
        cout << fibonacci[N] << endl;
    } else {
        for (int i = 18; i <= N; i++) {
            long long tmp = fibonacci[i-1] + fibonacci[i-2];
            fibonacci.push_back(tmp);
        }
        cout << fibonacci[N] << endl;
    }
    
    return 0;
}
