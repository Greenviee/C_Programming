#include <stdio.h>
#include "math.h"

int solution(int num) {
	int ret = 0;
	int i;
	for(i=0;i<4;i++) {
		if((num&(1<<i*2))!=0) ret += pow(2, i);
	}
		
	return ret;
}

int main() {
	int n;
	char c1, c2;
	c1 = getchar();
	c2 = getchar();
	if(c2!='\n') n = (c1-'0')*10 + (c2-'0');
	else n = c1-'0';
	printf("%d\n", solution(n));
}

