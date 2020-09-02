#include <iostream>
#include <queue>
using namespace std;
queue  <pair<int, int>> q;
char gear[4][8];
void rotate(int n, int dir) {
	char temp;
	int i;
	if (dir == 1) {
		temp = gear[n][7];
		for (i = 7; i > 0; i--) {
			gear[n][i] = gear[n][i - 1];
		}
		gear[n][0] = temp;
	}
	else {
		temp = gear[n][0];
		for (i = 0; i < 7; i++) {
			gear[n][i] = gear[n][i + 1];
		}
		gear[n][7] = temp;
	}
}
void fun(int n, int dir) {
	int d[4] = { 0 };
	int i;
	if (n == 0) {
		d[0] = dir;
		if (gear[0][2] != gear[1][6]) {
			d[1] = -d[0];
			if (gear[1][2] != gear[2][6]) {
				d[2] = -d[1];
				if (gear[2][2] != gear[3][6]) {
					d[3] = -d[2];
				}
			}
		}
		for (i = 0; i < 4; i++) {
			if (d[i] != 0) {
				rotate(i, d[i]);
			}
		}
	}
	else if (n == 1) {
		d[1] = dir;
		if (gear[1][6] != gear[0][2]) {
			d[0] = -d[1];
		}
		if (gear[1][2] != gear[2][6]) {
			d[2] = -d[1];
		}
		if (d[2] != 0) {
			if (gear[2][2] != gear[3][6]) {
				d[3] = -d[2];
			}
		}
		for (i = 0; i < 4; i++) {
			if (d[i] != 0) {
				rotate(i, d[i]);
			}
		}

	}
	else if(n == 2) {
		d[2] = dir;
		if (gear[2][6] != gear[1][2]) {
			d[1] = -d[2];
		}
		if (gear[2][2] != gear[3][6]) {
			d[3] = -d[2];
		}
		if (d[1] != 0) {
			if (gear[0][2] != gear[1][6]) {
				d[0] = -d[1];
			}
		}
		for (i = 0; i < 4; i++) {
			if (d[i] != 0) {
				rotate(i, d[i]);
			}
		}
	}
	else {
		d[3] = dir;
		if (gear[3][6] != gear[2][2]) {
			d[2] = -d[3];
			if (gear[2][6] != gear[1][2]) {
				d[1] = -d[2];
				if (gear[1][6] != gear[0][2]) {
					d[0] = -d[1];
				}
			}
		}
		for (i = 0; i < 4; i++) {
			if (d[i] != 0) {
				rotate(i, d[i]);
			}
		}
	}
}

int cal() {
	int result = 0;
	if (gear[0][0] == '1') {
		result += 1;
	}
	if (gear[1][0] == '1') {
		result += 2;
	}
	if (gear[2][0] == '1') {
		result += 4;
	}
	if (gear[3][0] == '1') {
		result += 8;
	}
	return result;
}

int  main() {
	
	int n;
	int i, j;
	int x, y;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			gear[i][j] = getchar();
		}
		getchar();
	}

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		q.push(make_pair(x, y));
	}
	for (i = 0; i < n; i++) {
		fun(q.front().first-1, q.front().second);
		q.pop();
	}
	cout << cal() << endl;
	return 0;
}