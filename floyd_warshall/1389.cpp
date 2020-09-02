#include <iostream>
using namespace std;
int n, m;
int rel[101][101];
int inf = 100;
int result[101];
int minuser;
int main() {
	int i,j,k;
	int r,c;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> r;
		cin >> c;
		rel[r][c] = 1;
		rel[c][r] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (rel[i][j] == 0 && i != j) {
				rel[i][j] = inf;
			}
		}
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (rel[i][k] + rel[k][j] < rel[i][j]) {
					rel[i][j] = rel[i][k] + rel[k][j];
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			result[i] += rel[i][j];
		}

		if (inf > result[i]) {
			inf = result[i];
			minuser = i;
		}
	}
	cout << minuser;
	return 0;
}