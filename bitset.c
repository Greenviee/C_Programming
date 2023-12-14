#include <stdio.h>
#include <math.h>

void solution(int n, int i) {
	if (pow(2, i) > n)
		return;
	if (n & (1 << i))
		printf("%d\n", i);
	solution(n ,i+1);
}

int main() {
	int n;
	scanf("%d", &n);
	solution(n, 0);
}
