#include <stdio.h>
#include <stdbool.h>

bool issymbol(char c) {
	if (c == '?' || c == '!' || c == '.' || c == ',' || c == ';' || c == ':' || c == '\'' || c == '\"' || c == '-' || c == '_')
		return true;
	return false;
}

int symbolcnt(char* s) {
	int len = strlen(s);
	int ret = 0;
	int i;
	for (i = 0; i < len; i++) 
		if (issymbol(s[i]))
			ret++;
	return ret;
}

char* filtersym(char* str) {
	char s[101];
	int i, j = 0;
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if (len-i-j < 0)
			break;
		while (issymbol(str[len-i-j]))
			j++;
		s[i] = str[len-i-j];
	}
	char* ret = malloc(sizeof(char)*(101-symbolcnt(str)));
	strcpy(ret, s);
	return ret;
}

int main() {
	char str[101][101];
	char answer[101][101];
	int i = 0;
	while (fgets(str[i], 101, stdin) == str[i]) {
		strcpy(answer[i], filtersym(str[i]));
		i++;
	}
	int j;
	for (j = 0; j < i; j++)
		printf("%s ", answer[j]);
}
