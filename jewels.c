#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}Coord;

int dist(Coord a, Coord b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	int field[101][101];
	int m, n;
	scanf("%d %d", &m, &n);
	int i, j;
	Coord here = {-1, -1};
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &field[i][j]);
			if (field[i][j] == -1) {
				here.x = i;
				here.y = j;
			}
		}
	}
	if (here.x == -1)
		printf("0");
	else {
		int mindist = 987654321;
		int value = -1;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (field[i][j] > 0) {
					Coord n = {i, j};
					int d = dist(n ,here);
					if (mindist > d) 
						mindist = d;
				}
			}
		}
		printf("%d", mindist);
	}
}
