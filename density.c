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
	char s[101][101];
	for (i = 0; i < n; i++) 
		scanf("%[^\n]s", s[i]);
	int alphabet = 0;
	for (i = 0; i < n; i++)
		alphabet += alphabetcnt(s[i]);
	int maxlen = -1;
	for (i = 0; i < n; i++) {
		int l = strlen(s[i]);
		if (maxlen < l)
			maxlen = l;
	}
	double answer = (double)alphabet / (double)(maxlen * n);
	printf("%lf", answer);
}
