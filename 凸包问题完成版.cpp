#include <iostream>
using namespace std;
#define NUM 7

typedef struct Point {
	float x;
	float y;
	int  signal=0;
} Point;
int   BruteForceConvexHull(Point P[], int n);


int main() {
	Point P[NUM];
	for (int i = 1; i < NUM; i++) {
		cin >> P[i].x >> P[i].y;
	}
	getchar();

	BruteForceConvexHull(P, NUM-1);
	cout << "属于凸包集合的点坐标为：" << endl;
	for (int i = 1; i <NUM; i++) {
		if (P[i].signal == 1) {
			cout << "    (" << P[i].x << "," << P[i].y << ")     "<<endl;
		}
	}
	getchar();
	return 1;
}
int  BruteForceConvexHull(Point P[], int n) {
	int i = 1, j = 1, k = 1;
	float a, b, c;
	int sign1 = 0, sign2 = 0;
	for (; i <= n - 1; i++) {
		for (j = i + 1; j <= n; j++) {
			a = P[j].y - P[i].y;
			b = P[i].x - P[j].x;
			c = P[i].x*P[j].y - P[i].y*P[j].x;
			sign1 = 0;
			sign2 = 0;
			for (k = 1; k <= n; k++) {
				if (k == i || k == j) {
					continue;
				}
				if ((a*P[k].x + b*P[k].y - c) <= 0) {
					sign1--;
				}
				if ((a*P[k].x + b*P[k].y - c) >= 0) {
					sign2++;
				}

			}
			if ((sign1 == 2 - n) || (sign2 == n - 2)) {
				P[i].signal = 1;
				P[j].signal = 1;
			}
		}
	}
	return 1;
}
