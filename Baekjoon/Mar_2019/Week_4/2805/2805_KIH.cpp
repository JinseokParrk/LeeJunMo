/*
 풀이에 걸린 시간 : 92분
 복잡도 계산 : NlogN + 2N 이므로 O(NlogN)
 수행 시간 : 520ms
 메모리 : 10468KB
 오답 이유 :
    걍 인덱스가 엄청 꼬여서 에러나면서 오래걸림
 풀이 방법 :
    나무들이 길이가 담긴 배열을 중복 제거하고 내림차순으로 정렬 - key
    나무길이 당 나무의 숫자를 갖고있는 dictionary 생성 - dictionary
    key 값을 큰 값 부터 조회하면서 잘려진 나무 길이를 계산
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // 문제 조건 입력
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> arr(N, 0);
    
    for (int i =0; i < N; i++) {
        cin >> arr[i];
    }
    
    // 나무의 크기 순으로 정렬
    // 여기서 N*logN
    sort(arr.begin(), arr.end()); // nlogn
    
    vector<int> key(N , 0);
    map<int, int> dict;
    
    // Dictionary 자료형과 이를 순서대로 참조하기 위해서
    // Dictionary 의 Key 값만을 내림차순으로 담은 배열을 만듦
    // 여기서 이 과정이 C++ 에서 비효율 적인 것 같음(다른 방법이 있을 것 같은데)
    for (int i = 0; i < N; i++) {
        key[N - 1 - i] = arr[i];
        auto tmp = dict.find(arr[i]);
        if (tmp == dict.end()) {
            dict.insert(make_pair(arr[i], 1));
        } else {
            tmp->second += 1;
        }
    }
    
    // key 값 중복 제거
    vector<int>::iterator ut = unique(key.begin(), key.end());
    key.erase(ut, key.end());
    
    int result = 0, num = 0;
    int idx = 0;
    
    // 중복 제거된 Key 값을 기준으로 순회하면서
    // 잘려진 나무길이가 구하고자 하는 나무길이보다 같거나 커지는 순간을 잡음
    while (result < M && idx < key.size()) {
        num += dict[key[idx]];
        result += (key[idx] - key[idx + 1]) * num;
        idx += 1;
    }
    
    // 만약 같으면 바로 출력
    if (result == M) {
        cout << key[idx] << endl;
    }
    // 잘려진 나무길이가 구하고자 하는 나무길이보다 클 경우에는
    // 다시 이전 단계로 돌아가서 1칸씩 수를 늘리면서 찾음
    else {
        idx -= 1;
        result -= (key[idx] - key[idx + 1]) * num;

        int more = 0;
        
        while (result < M) {
            more += 1;
            result += num;
        }
        cout << key[idx] - more << endl;
    }
    
    return 0;
}
