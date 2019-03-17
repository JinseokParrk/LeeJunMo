/*
 풀이에 걸린 시간 : 37분
 복잡도 계산 : O(N)
    완전탐색으로 하였을 경우, 최악의 조건은 N개의 배열에서 N/2번의 탐색을 진행하게 되는 상황이다.
    이럴 경우에는 Big-O Notation 값이 N^2 이 된다.
    풀이 방법과 같은 경우에는 head와 tail이 모두 N 번 움직였을 때가 된다. 따라서 2N 이 되므로
    O(N) 이된다.
 수행 시간 : 4ms
 메모리 : 1988KB
 오답 이유 :
    완전탐색으로 했다가 시간초과되었읍
 풀이 방법 :
    Loop : headIdx 가 N 을 가리킬 때까지 반복한다.
    1. sum 이 M 이랑 같으면 result + 1 하고, tailIdx + 1, headIdx + 1 하고 각 값을 더한다.
    2. sum 이 M 보다 작으면 headIdx + 1, 하고 그 값을 받는다.
    3. sum 이 M 보다 크면 tailIdx 값많큼 빼고, tailIdx + 1 하고 그 값을 더한다.
 */

#include <iostream>
#include <vector>

using namespace std;

void upTail(int &tailId, int &sum, const int arr[]) {
    sum -= arr[tailId++];
}

void upHead(int &headId, int &sum, const int arr[]) {
    sum += arr[++headId];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int *arr = new int[N];
    
    for (int i =0; i < N; i++) {
        cin >> arr[i];
    }
    
    int headIdx = 0;
    int tailIdx = 0;
    int sum = arr[0];
    int result = 0;
    
    while (headIdx < N) {
        if (sum == M) {
            // 결과값 증가
            result += 1;
            
            // 배열을 가리키는 2개의 인덱스 증가 및 sum 값 변화
            upHead(headIdx, sum, arr);
            upTail(tailIdx, sum, arr);
        }
        
        else if (sum > M) {
            // tail 인덱스 1 증가 및 sum 값 차감
            upTail(tailIdx, sum, arr);
        }
        
        else {
            // head 인덱스 1증가 및 sum 값 증가
            upHead(headIdx, sum, arr);
        }
    }
    
    cout << result << endl;
    
    delete[] arr;
    arr= nullptr;
    
    return 0;
}
