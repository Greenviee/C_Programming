#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare (void *first, void *second)
{
    if (*(int*)first < *(int*)second)
        return 1;
    else if (*(int*)first > *(int*)second)
        return -1;
    else 
        return 0;
}
 
 int getWeight(char* str) {
 	int ret = 0;
 	int i, len = strlen(str);
 	if (str[0] == '-' || str[0] == '+' || (('0' <= str[0]) && (str[0] < '9'))) {
 		return abs(atoi(str));
	 }
	 else {
	 	for (i = 0; i < len; i++)
	 		ret += str[i];
	 	return ret;
	 }
 }
 
int main() {
	int n;
	char str[101][101];
	int weights[101];
	scanf("%d", &n);
	int i;
	for(i = 0;i < n; i++) {
		scanf("%s", &str[i]);
		weights[i] = getWeight(str[i]);
	}
	qsort(weights, n, sizeof(int), compare);
	int second_weight;
	for (i = 1; i < n; i++) {
		if (weights[i] < weights[0]) {
			second_weight = weights[i];
			break;
		}
	}
	for (i = 0; i < n; i++) {
		if (getWeight(str[i]) == second_weight) {
			if ('0' <= str[i][0] && str[i][0] <= '9')
				printf("+");
			printf("%s ", str[i]);
		}
	}
	printf("\n%d", second_weight);
}
