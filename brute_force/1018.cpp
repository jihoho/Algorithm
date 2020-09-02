#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;
char d[51][51];
string w_first[8] = {
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
};
string b_first[8] = {
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
};

int color_check(int x, int y) {
	int ch_1 = 0;int ch_2 = 0;

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			if (d[x + i][y + j] != w_first[i][j])
				ch_1 += 1;
		}
	}
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			if (d[x + i][y + j] != b_first[i][j])
				ch_2 += 1;
		}
	}
	
	return ch_1 > ch_2 ? ch_2 : ch_1;

}

int simul(int n, int m) {
	int _min = 8 * 8;
	int tmp;
	for (int i = 1; i <= n - 8+1; i++) {
		for (int j = 1; j <= m - 8+1; j++) {
			tmp = color_check(i, j);
			if (_min > tmp)_min = tmp;
		}
	}
	return _min;
}
int main() {
	int n, m;
	memset(d,0, sizeof(d));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> d[i][j];
		}
	}
	cout << simul(n, m) << endl;
}