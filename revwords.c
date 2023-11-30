#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool issymbol(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return false;
	return true;
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
		if (len-i-j-1 < 0)
			break;
		while (issymbol(str[len-i-j-1])) {
			j++;
			if (len-i-j-1 < 0)
				break;
		}
		if (len-i-j-1 < 0)
			break;
		s[i] = str[len-i-j-1];
	}
	s[i] = NULL;
	char* ret = malloc(sizeof(char)*(101-symbolcnt(str)));
	strcpy(ret, s);
	return ret;
}

int main() {
	char str[256];
	char split[101][101];
	char answer[101][101];
	int i = 0;
	fgets(str, 256, stdin);
	char *ptr = strtok(str, " ");    

    while (ptr != NULL)              
    { 
    	strcpy(answer[i], filtersym(ptr));
    	i++;
        ptr = strtok(NULL, " ");      
    }
	int j;
	for (j = 0; j < i; j++)
		printf("%s ", answer[j]);
}
