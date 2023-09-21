#include <stdio.h>

int main() 
{
	int n;
	float num;
	scanf("%d %f", &n, &num);
	printf("0.");
	int i;
	for (i = 0; i < n; i++) {
		num *= 2;
		if (num >= 1.0) {
			printf("1");
			num -= 1;
		}
		else
			printf("0");
	} 
	printf("\n");
	return 0;
}
