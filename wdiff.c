#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	return false;
}

int getX(char* s) {
	int i;
	int ret = 0;
	for (i = 0; i < 41; i++) {
		if (s[i] == NULL) break;
		if (isVowel(s[i])) ret++; 
	}
	return ret;
}

int getY(char* s) {
	int i;
	int ret = 0;
	for (i = 0; i < 41; i++) {
		if (s[i] == NULL) break;
		if (!isVowel(s[i])) ret++; 
	}
	return ret;
}

int main() {
	char w1[41], w2[41];
	scanf("%50s %50s", &w1, &w2);
	double x1, x2, y1, y2;
	x1 = getX(w1);
	x2 = getX(w2);
	y1 = getY(w1);
	y2 = getY(w2);
	double answer = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	printf("%.3lf", answer);
}
