/*
풀이에 걸린 시간 : 50분
복잡도 계산 : -
수행 시간 : 0ms
메모리 : 1116KB
풀이 방법 : 입력값이 항상 루트부터 나온다는 보장이 없으므로 입력값 하나에 대한 양쪽자식을 저장하였음.
			이후, 재귀함수를 이용하여 루트부터 찾아자식을 찾아 그 자식의 자식을 찾아가는 방법을 이용하였음.
*/
#include <stdio.h>

void pre(int node);
void in(int node);
void post(int node);

int my_tree[26][2];
int main() {
	int n;
	char I, left, right;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		/*
		I(나)의 왼쪽자식과 오른쪽 자식을 저장
		*/
		scanf(" %c %c %c", &I, &left, &right);
		if (left != '.')
			my_tree[I - 'A'][0] = left - 'A';
		else
			my_tree[I - 'A'][0] = -1;

		if (right != '.')
			my_tree[I - 'A'][1] = right - 'A';
		else
			my_tree[I - 'A'][1] = -1;

	}

	pre(0);
	printf("\n");
	in(0);
	printf("\n");
	post(0);
}


void pre(int node) {
	if (node == -1) return;
	printf("%c", node + 'A');
	pre(my_tree[node][0]);
	pre(my_tree[node][1]);
}
void in(int node) {
	if (node == -1) return;
	in(my_tree[node][0]);
	printf("%c", node + 'A');
	in(my_tree[node][1]);
}
void post(int node) {
	if (node == -1) return;
	post(my_tree[node][0]);
	post(my_tree[node][1]);
	printf("%c", node + 'A');
}


