#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
	char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
	int i;
	for (i = 0; i < 5; i++) {
		if (c == vowel[i] || c == vowel[i] + ('a' - 'A'))
			return true;
	}
	return false;
}

int getX(char* s) {
	int i;
	int ret = 0;
	for (i = 0; i < strlen(s); i++) {
		if (isVowel(s[i]))
			ret++; 
	}
	return ret;
}

int getY(char* s) {
	int i;
	int ret = 0;
	for (i = 0; i < strlen(s); i++) {
		if (!isVowel(s[i]))
			ret++; 
	}
	return ret;
}

double getLen(double x1, double x2, double y1, double y2) {
	double ret;
	ret = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return ret;
}

double Heron(double l1, double l2, double l3) {
	double s = (l1 + l2 + l3) / 2;
	return sqrt(s*(s-l1)*(s-l2)*(s-l3));
}

int main() {
	char s1[41], s2[41], s3[41];
	double len1, len2, len3;
	scanf("%50s %50s %50s", &s1, &s2, &s3);
	double x1, x2, x3, y1, y2, y3;
	x1 = getX(s1);
	x2 = getX(s2);
	x3 = getX(s3);
	y1 = getY(s1);
	y2 = getY(s2);
	y3 = getY(s3);
	len1 = getLen(x1, x2, y1, y2);
	len2 = getLen(x2, x3, y2, y3);
	len3 = getLen(x3, x1, y3, y1);
	double answer = Heron(len1, len2, len3);
	printf("%.3lf", answer);
}
