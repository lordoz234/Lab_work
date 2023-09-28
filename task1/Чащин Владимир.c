#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
int x1, y1, x2, y2;
int vx, vy;
bool fl = false;

void main() {
	printf("Input coordinates (X1,Y1,X2,Y2) from 1 to 8 (including) \n");
	scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
	vx = abs(x2 - x1);
	vy = abs(y2 - y1);
	if (vx == 0 && vy == 0) {
		printf("korol \n");
	}
	if (vx == vy) {
		printf("ferz \nslon \n");
		fl = true;
		if (vx == 1) {
			printf("korol \n");
		}
	}
	if (vx == 0 || vy == 0) {
		printf("ferz \ntura \n");
		fl = true;
		if (vx == 1 || vy == 1) {
			printf("korol \n");
		}
	}
	if ((vx == 2 && vy == 1) || (vx == 1 && vy == 2)) {
		fl = true;
		printf("kon \n");
	}
	if (fl==false){
		printf("no such chess piecess");
	}
}