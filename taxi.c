#include <stdio.h>

typedef enum {N, E, W, S} Dir;

int main() {
	char c;
	int num;
	int x = 0, y = 0;
	Dir d = 1;
	while (scanf("%c", &c) != EOF) {
		switch(c) {
		case 'B':
			scanf("%d", &num);
			switch(d) {
			case 0:
				y -= num;
				break;
			case 1:
				x -= num;
				break;
			case 2:
				y += num;
				break;
			case 3:
				x += num;
				break;
			}
			break;
		case 'F':
			scanf("%d", &num);
			switch(d) {
			case 0:
				y += num;
				break;
			case 1:
				x += num;
				break;
			case 2:
				y -= num;
				break;
			case 3:
				x -= num;
				break;
			}
			break;
		case 'L':
			d = (d + 4 - 1) % 4;
			break;
		case 'R':
			d = (d + 4 + 1) % 4;
			break;
		}
	}
	char direction;
	switch(d) {
	case 0:
		direction = 'N';
		break;
	case 1:
		direction = 'E';
		break;
	case 2:
		direction = 'S';
		break;
	case 3:
		direction = 'W';
		break;
	}
	printf("%d %d\n%c", x, y, direction);
}
