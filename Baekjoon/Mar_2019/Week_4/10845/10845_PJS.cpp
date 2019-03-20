/*
풀이에 걸린 시간 : 1시간
복잡도 계산 :
수행 시간 :
메모리 : B
오답 이유 : 알수가없다.
풀이 방법 : 원형 큐로 구현했지만 굳이 원형으로 안해도될듯하다. N이 주어지고 push 만 N번 한다고 했을때
			큐 배열 길이를 N+1으로 주면 최대 N개가 들어갈 수 있으니까 인덱스 0으로 돌아올 일이없다.
*/

#include<iostream>
#include <sstream>
using namespace std;

// 원형 큐는 한 개가 비어있다.

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/


int main() {
	int N;
	cin >> N;
	cin.ignore();
	int *queue = new int[N+1];
	int front = 0, rear = 0;

	while (N--) {
		string s;
		string k[2];
		int i = 0;
		getline(cin, s);

		stringstream ss(s);
		while (ss >> k[i]) {
			i++;
		}

		if (k[0].compare("push") == 0) {
			int num = atoi(k[1].c_str());
			/*if ((rear + 1) % (N+1) == front) { // 큐가 가득차 있으면
				printf("-1\n");
			}*/
			rear = (rear + 1) % (N+1);
			queue[rear] = num;
		}
		else if (k[0].compare("pop") == 0) {			
			(front == rear) ? printf("-1\n") : printf("%d\n", queue[++front]);
		}
		else if (k[0].compare("size") == 0) {
			if (rear < front) { rear = rear + (N+1); }
			printf("%d\n", rear-front);
		}
		else if (k[0].compare("empty") == 0) {
			(front == rear) ? printf("1\n") : printf("0\n");
		}
		else if (k[0].compare("front") == 0) {
			(front == rear) ? printf("-1\n") : printf("%d\n",queue[front+1]);
		}
		else if (k[0].compare("back") == 0) {
			(front == rear) ? printf("-1\n") : printf("%d\n", queue[rear]);
		}
	}
	delete[] queue;
	return 0;
}