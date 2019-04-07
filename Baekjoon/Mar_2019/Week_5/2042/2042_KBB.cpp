
/*
풀이에 걸린 시간 : -
복잡도 계산 : -
수행 시간 : 228ms
메모리 : 17520KB
풀이 방법 : 이진 트리를 이용하여 구간별 합을 구하였음
                                   48				
	   ex)                20        28
	   		 8         12        16
		    3         5         7	  9
	       1         2         3         4         5
*/
#include <stdio.h>

long long section[2100000];
int start = 1;

void do_sum();
void do_change(int seq, long long num);
void do_printf(int s, int e);
int main() {
	
	int n, m, k;
	int a;
	long long b, c;
	
	scanf("%d %d %d", &n, &m, &k);

	while (n > start) start *= 2;
	for (register int i = 0; i < n; ++i) {
		scanf("%lld", &section[start + i]);
	}
	do_sum();
	for (register int i = 0; i < (m + k); ++i) {
		scanf("%d %lld %lld", &a, &b, &c);
		if (a == 1) do_change(b, c);
		else do_printf(b, c);
	}

	return 0;
}
void do_sum() {
	for (register int i = start; i > 0; i /= 2) {
		for (register int j = 0; j < i - 1; j += 2) {
			section[(i + j) / 2] = section[i + j] + section[i + j + 1];
		}
	}
}
void do_change(int seq, long long num) {
	section[seq + start - 1] = num;
	for (register int i = start + seq - 1; i > 0; i /= 2) {
		if(i % 2)
			section[i / 2] = section[i] + section[i - 1];
		else
			section[i / 2] = section[i] + section[i + 1];
	}
}
void do_printf(int s, int e) {
	long long sum = 0;
	s += start - 1;
	e += start - 1;
	while (s < e) {
		if (s % 2) {
			sum += section[s];
			s += 1;
		}
		if (e % 2 == 0) {
			sum += section[e];
			e -= 1;
		}
		s /= 2;
		e /= 2;
	}
	if (s == e) sum += section[s];
	printf("%lld\n", sum);
}
