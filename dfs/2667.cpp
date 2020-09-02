#include <iostream>
using namespace std;
int n;
int arr[25][25];
int x_dir[] = { -1,1,0,0 };
int y_dir[] = { 0,0,-1,1 };
int apart[25 * 25+1];
int visit[25][25];
int a_num;
void dfs_apart(int r, int c);
void sort(int* arr, int count) {
	int i, j;
	int temp;
	for (i = 1; i <= count; i++) {
		for (j = i + 1; j <= count; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main() {
	int i, j;
	cin >> n;
	getchar();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			arr[i][j]=getchar()-48;
		}
		getchar();
	}
	getchar();
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1&&visit[i][j]==0) {
				a_num ++;
				dfs_apart(i, j);
			}
		}
	}
	sort(apart, a_num);
	cout << a_num << endl;
	for (i = 1; i <= a_num; i++) {
		cout << apart[i] << endl;
	}
	return 0;
}

void dfs_apart(int r, int c) {
	int next_r, next_c;
	int i;
	visit[r][c] = 1;
	if (arr[r][c] == 1) {
		apart[a_num]++;
		for (i = 0; i < 4; i++) {
			next_r = r + x_dir[i];
			next_c = c + y_dir[i];
			if ((next_r >= 0) && (next_r < n) && (next_c >= 0) && (next_c < n)&&visit[next_r][next_c]==0) {
				dfs_apart(next_r, next_c);
			}
		}
	}
}