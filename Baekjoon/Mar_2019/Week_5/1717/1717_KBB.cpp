#include <stdio.h>
/*
풀이에 걸린 시간 : -
복잡도 계산 : -
수행 시간 : 52ms
메모리 : 5020KB
풀이 방법 : union 방법을 이용하였는데 자신의 부모를 저장하는 방법이 두가지가 있음.
           1) 자신의 바로 위 부모를 저장하는 방법
           2) 자신의 최상위 부모를 저장하는 방법
           
           이 문제는 같은 집합에 속해있는지만 확인하면 되는 것이기 때문에 2)를 사용하여 최상위 부모가 같으면 같은 집합에 포함되어 있는것으로
           'YES'를 출력하도록 하였다.
*/


int s[1000001];

void init(int n);
int find(int a);
int main()
{
	int n, m;
	int opt, a, b;
	scanf("%d %d", &n, &m);
	init(n);
	for (int command = 0; command < m; ++command) {
		scanf("%d %d %d", &opt, &a, &b);
		if (opt) {
			find(a);
			find(b);

			if (s[a] == s[b])
				printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			int pa, pb;
			pa = find(a);
			pb = find(b);
			s[pb] = pa;
			
		}
	}
	
	return 0;
}
int find(int a) {
	if (s[a] != a)
		return (s[a] = find(s[a]));
	else
		return a;
}
void init(int n) {
	for (register int i = 0; i <= n; ++i) {
		s[i] = i;
	}
}
