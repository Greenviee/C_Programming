#include <stdio.h>
#include <string.h>

int caseD(int num) {
	num *= 2;
	return num;
}

int caseA(int num) {
	num++;
	return num;
}

int caseS(int num) {
	num--;
	return num;
}

int caseH(int num) {
	num /= 2;
	return num;
}

int main() {
	int num, i;
	char str[100];
	scanf("%d", &num);
	scanf("%s", &str);
	int len = strlen(str);
	int (*dash[100])();
	dash[0] = caseA;
	dash['D' - 'A'] = caseD;
	dash['S' - 'A'] = caseS;
	dash['H' - 'A'] = caseH;
	for (i = 0; i < len; i++) {
		num = dash[str[i] - 'A'](num);
	}
	printf("%d", num);
}
