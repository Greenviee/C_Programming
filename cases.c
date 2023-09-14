#include <stdio.h>

int main() {
	char c = getchar();
	if(c=='Z') printf("%c\n", 'A');
	else if(c>='A' && c<='Z') printf("%c\n", c+1);
	else if(c=='a') printf("%c\n", 'z');
	else printf("%c\n", c-1);
}
