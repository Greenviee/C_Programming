#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool isvowel(char c) {
	switch(c) {
	case 'a':
		return true;
		break;
	case 'e':
		return true;
		break;
	case 'i':
		return true;
		break;
	case 'o':
		return true;
		break;
	case 'u':
		return true;
		break;
	}
	return false;
}

bool isconsonant(char c) {
	switch(c) {
	case 'a':
		return false;
		break;
	case 'e':
		return false;
		break;
	case 'i':
		return false;
		break;
	case 'o':
		return false;
		break;
	case 'u':
		return false;
		break;
	case ' ':
		return false;
		break;
	}
	return true;
}

int main() {
	char s[101];
	scanf("%[^\n]s", &s);
	int i = 0, x = 0, y = 0;
	while (!isupper(s[i])) {
		if (isvowel(s[i]))
			x++;
		else if (isconsonant(s[i]))
			y++;
		else
			y--;
		i++;
	}
	printf("%d %d", x, y);
}
