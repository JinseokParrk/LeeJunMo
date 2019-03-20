/*
Ǯ�̿� �ɸ� �ð� : 1�ð�
���⵵ ��� :
���� �ð� :
�޸� : B
���� ���� : �˼�������.
Ǯ�� ��� : ���� ť�� ���������� ���� �������� ���ص��ɵ��ϴ�. N�� �־����� push �� N�� �Ѵٰ� ������
			ť �迭 ���̸� N+1���� �ָ� �ִ� N���� �� �� �����ϱ� �ε��� 0���� ���ƿ� ���̾���.
*/

#include<iostream>
#include <sstream>
using namespace std;

// ���� ť�� �� ���� ����ִ�.

/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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
			/*if ((rear + 1) % (N+1) == front) { // ť�� ������ ������
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