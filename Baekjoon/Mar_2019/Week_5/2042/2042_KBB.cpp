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
