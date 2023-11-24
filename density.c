#include <stdio.h>
#include <string.h>

int alphabetcnt(char* s) {
	int ret = 0;
	int i;
	for (i = 0; i < strlen(s); i++) 
		if (s[i] != ' ')
			ret++;
	return ret;
}

int main() {
	int i, n;
	scanf("%d", &n);
	while ((getchar()) != '\n');

    char str[101][101];
    for (i = 0; i < n; i++) {
        scanf(" %[^\n]", str[i]);
    }
	int alphabet = 0;
	for (i = 0; i < n; i++)
		alphabet += alphabetcnt(str[i]);
	int maxlen = -1;
	for (i = 0; i < n; i++) {
		int l = strlen(str[i]);
		if (maxlen < l)
			maxlen = l;
	}
	double answer = (double)alphabet / (double)(maxlen * n) * 100;
	printf("%.2lf", answer);
}
