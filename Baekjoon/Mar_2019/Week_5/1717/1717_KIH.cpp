/*
 풀이에 걸린 시간 : 1시간 20분
 복잡도 계산 : -
 수행 시간 : 56ms
 메모리 : 8144KB
 오답 이유 : 처음에는 최대한 빨리 풀기 위해서 메모리를 많이 사용하는 방식으로
           다음에는 union-find 라는 것을 찾아보고 해결
           https://brenden.tistory.com/33
 풀이 방법 : -
 */

#include <iostream>
#include <vector>

using namespace std;


int doFind(int x, vector<int>& parent) {
    if (x == parent[x])
        return x;
    else {
        parent[x] = doFind(parent[x], parent);
        return parent[x];
    }
}

void doUnion(int x, int y, vector<int>& parent) {
    int tmpx = doFind(x, parent);
    int tmpy = doFind(y, parent);
    
    if (tmpx != tmpy) {
        parent[tmpy] = tmpx;    // 최상위 부모들만 연결해주면 된다.
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    vector<int> arr;
    vector<bool> result;
    
    for (int i = 0; i < N+1; i++) {
        arr.push_back(i);
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == 0) {
            doUnion(b, c, arr);
        }
        else {
            if (doFind(b, arr) == doFind(c, arr)) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
    }
    
    for (auto e : result) {
        if (e)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}

/* 메모리 초과
int main() {
    int N, M;
    
    cin >> N;
    cin >> M;
    //scanf("%d %d", &N, &M);
    //cout << "input : " << N <<","<<M<<endl;

    vector<int> arr(N+1, 0);        // 각 원소별로 어떤 집합에 속해있는지 기록
    vector<vector<int>> setArr;     // 집합별로 어떤 원소들이 있는지 기록
    vector<bool> result;            // 결과 기록
    int key = 1;
    
    for (int i = 0; i < M; i++) {
        int a,b,c;
        cin >> a;
        cin >> b;
        cin >> c;
        //scanf("%d %d %d", &a, &b, &c);
        
        // a 가 0일 경우 : 합집합 연산
        if (a == 0) {
            // 두개의 원소 모두가 아직 자기 자신이 집합의 전부일 경우
            if (arr[b] == 0 && arr[c]==0) {
                // key 이름을 갖는 집합에 넣기
                arr[b] = key;
                arr[c] = key;
                
                vector<int> tmp;
                tmp.push_back(b);
                tmp.push_back(c);
                setArr.push_back(tmp);
                
                // 새롭게 할당한 key 이므로 증가
                key++;
            }
            // 같은 경우는 패스
            else if (arr[b] == arr[c]) {
                continue;
            }
            // 두개 모두 각자의 집합이 설정되어 있을 경우
            else if (arr[b] != 0 && arr[c] != 0) {
                // 한쪽 집합의 key 를 버리고 반대쪽으로 모은다
                int leftKey = arr[b];
                int rightKey = arr[c];
                
                // arr 에 c가 속한 집합의 모든 원소들의 key값 변경 및 집합 변경
                for(int i = 0; i < setArr[rightKey - 1].size(); i++) {
                    arr[setArr[rightKey - 1][i]] = leftKey;
                    setArr[leftKey - 1].push_back(setArr[rightKey - 1][i]);
                }
                
                setArr[rightKey - 1].clear();
            }
            // 한개의 원소만
            else {
                int leftKey = arr[b];
                int rightKey = arr[c];
                
                if (arr[b] != 0) {
                    arr[c] = arr[b];
                    setArr[leftKey - 1].push_back(c);
                }
                else {
                    arr[b] = arr[c];
                    setArr[rightKey - 1].push_back(b);
                }
            }
        }
        
        // a 가 1일 경우 : 체크
        else {
            if (arr[b] == arr[c]) {
                if (arr[b] == 0) {
                    result.push_back(false);
                }
                else
                    result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
    }
    
    for (auto e : result) {
        if (e) {
            printf("YES\n");
        } else
            printf("NO\n");
    }
    
    return 0;
}
*/
