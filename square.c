#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isnum(char c) {
	return ('0' <= c) && (c <= '9');
}

char* square(char* str) {
	int len = strlen(str);
	char* reverse = malloc(sizeof(char) * 1000);
	char* ret = malloc(sizeof(char) * 1000);
	int i, t = 0;
	for (i = 0; i < len; i++) 
		reverse[i] = str[len-i-1];
	for (i = 0 ; i < len; i++) {
		switch(isnum(reverse[i])) {
		case false:
			switch(reverse[i]) {
			case '-':
			case '+':
				break;
			case ' ':
				ret[t++] = ' ';
				break;
			default:
				ret[t++] = reverse[i];
				ret[t++] = reverse[i];
				break;			
			}
			break;
		case true:
			{
				int sqrt = (reverse[i] - '0') * (reverse[i] - '0');
				switch(sqrt > 9) {
				case true:
					ret[t++] = (sqrt / 10) + '0';  
					ret[t++] = (sqrt % 10) + '0';
					break;
				case false:
					ret[t++] = sqrt + '0';
					break;
				}
			break;
			}
		}
	}
	for (i = 0; i < t; i++)
		printf("%c", ret[i]);
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char c[101];
	scanf("%[^\n]s", &c);
	char answer[1001];
	square(c);
}
