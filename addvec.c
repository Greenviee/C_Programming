#include <stdio.h>
#include <math.h>
#define PI 3.141592
typedef struct {
	int x;
	int y;
}Vector;

int main() {
	Vector v1, v2, v3;
	scanf("%d %d", &v1.x, &v1.y);
	scanf("%d %d", &v2.x, &v2.y);
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	if (v3.y == 0) {
		if (v3.x >= 0)
			printf("0.00");
		else 
			printf("180.00");
	}
	else {
		double t = (double)v3.y / (double)v3.x;
		double rad = atan(t);
		double degree = rad*180 / PI;
		printf("%.2lf", degree);
	}
}
