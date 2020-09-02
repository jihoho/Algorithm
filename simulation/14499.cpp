#include <iostream>
using namespace std;
int dice[4][3];

int map[20][20];
int n, m, x, y, k;
int com[1001];

int simul(int* x, int* y, int k) {
	int a, b,i,j;
	int temp[4][3];
	if (k == 1) {
		a = *x, b = *y + 1;
		if (b >= m) {
			return -1;
		}
		for (i = 0; i < 4; i++) {
			temp[i][1] = dice[i][1];
		}
		temp[1][0] = dice[1][0], temp[1][2] = dice[1][2];
		dice[1][0] = temp[3][1], dice[1][1] = temp[1][0],
		dice[1][2] = temp[1][1], dice[3][1] = temp[1][2];
		if (map[a][b] == 0) {
			map[a][b] = dice[3][1];
		}
		else {
			dice[3][1] = map[a][b];
			map[a][b] = 0;
		}

	}
	else if (k == 2) {
		a = *x, b = *y - 1;
		if (b < 0) {
			return -1;
		}
		for (i = 0; i < 4; i++) {
			temp[i][1] = dice[i][1];
		}
		temp[1][0] = dice[1][0], temp[1][2] = dice[1][2];
		dice[1][0] = temp[1][1], dice[1][1] = temp[1][2],
		dice[1][2] = temp[3][1], dice[3][1] = temp[1][0];
		if (map[a][b] == 0) {
			map[a][b] = dice[3][1];
		}
		else {
			dice[3][1] = map[a][b];
			map[a][b] = 0;
		}
	}
	else if (k == 3) {
		a = *x-1, b = *y;
		if (a <0) {
			return -1;
		}
		for (i = 0; i < 4; i++) {
			temp[i][1] = dice[i][1];
		}
		temp[1][0] = dice[1][0], temp[1][2] = dice[1][2];

		dice[0][1] = temp[1][1], dice[1][1] = temp[2][1],
		dice[2][1] = temp[3][1], dice[3][1] = temp[0][1];
		if (map[a][b] == 0) {
			map[a][b] = dice[3][1];
		}
		else {
			dice[3][1] = map[a][b];
			map[a][b] = 0;
		}
	}
	else if (k == 4) {
		a = *x+1, b = *y;
		if (a >= n) {
			return -1;
		}
		for (i = 0; i < 4; i++) {
			temp[i][1] = dice[i][1];
		}
		temp[1][0] = dice[1][0], temp[1][2] = dice[1][2];

		dice[0][1] = temp[3][1], dice[1][1] = temp[0][1],
		dice[2][1] = temp[1][1], dice[3][1] = temp[2][1];
		if (map[a][b] == 0) {
			map[a][b] = dice[3][1];
		}
		else {
			dice[3][1] = map[a][b];
			map[a][b] = 0;
		}
	}
	*x = a; *y = b;
	return 0;
}

int main() {
	int i, j;
	cin >> n >> m >> x >> y >> k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (i = 0; i < k; i++) {
		cin >> com[i];
		if (simul(&x, &y, com[i]) == 0) {
			cout << dice[1][1] << endl;
		}
	}

	return 0;
}