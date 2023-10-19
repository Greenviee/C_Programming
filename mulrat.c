#include <stdio.h>
typedef int Rational;

int gcd(int x, int y) {
	if (x == y)
		return x;
	else if(x > y)
		return gcd(y, x);
	else
		return gcd(x, y-x);
}

int main() {
	Rational n1, n2, n3, d1, d2, d3;
	scanf("%d %d", &n1, &d1);
	scanf("%d %d", &n2, &d2);
	n3 = n1 * n2;
	d3 = d1 * d2;
	Rational GCD = gcd(n3, d3);
	printf("%d/%d", n3/GCD, d3/GCD);
}
