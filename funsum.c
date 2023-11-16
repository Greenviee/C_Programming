#include <stdio.h>

int noteven(int* arr, int size) {
	int ret = 0, i;
	for (i = 0; i < size; i++) 
		ret += arr[i];
	return ret;
}

int even(int* arr, int size) {
	int ret = arr[0] ^ arr[1], i;
	for (i = 2; i < size; i++) 
		ret ^= arr[i];
	return ret;
}

int main() {
	int arr[1001];
	int i = 0, j;
	int (*solution[])() = {even, noteven};
	do {
		scanf("%d", &arr[i]);
		i++;
	} while (getchar() == ' ');
	int ret = 0;
	ret = solution[arr[0] % 2](arr, i);
	printf("%d", ret);
}
