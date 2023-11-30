#include <stdio.h>
#include <string.h>

#define swap(a, b) {char tmp=a; a=b; b=tmp;}

char* revstr(char* s) {
	int len = strlen(s);
	char* ret = malloc(sizeof(char)*101);
	char l[101];
	int i;
	for (i = len; i > 0; i--) {
		swap(l[len-i], s[i-1]);
	}
	strcpy(ret, l);
	return ret;
}

int main() {
	char str[101][101];
	int i = 0;
	while (scanf("%s", &str) != EOF) {
		char answer[101];
		int len = strlen(str);
		strcpy(answer, revstr(str));
		answer[len] = NULL;
		printf("%s\n", answer);
	}
}
