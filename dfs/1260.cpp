#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
char d[1001][1001];

void dfs(int start,int n) {
	char visited[1001];

	memset(visited, 0, sizeof(visited));
	stack <int> s;
	s.push(start);
	visited[start] = 1;
	printf("%d ", start);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		for (int i = 1; i <= n; i++) {
			if (d[cur][i]==1&&visited[i]==0) {
				printf("%d ", i);
				s.push(cur);
				s.push(i);
				visited[i] = 1;
				break;
			}
		}
	}
	printf("\n");
}

void bfs(int start, int n) {
	char visited[1001];

	memset(visited, 0, sizeof(visited));
	queue <int> q;
	q.push(start);
	visited[start] = 1;
	printf("%d ", start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (d[cur][i] == 1 && visited[i] == 0) {
				printf("%d ", i);
				q.push(i);
				visited[i] = 1;
			}
		}
	}

	printf("\n");
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		d[x][y] = 1;
		d[y][x] = 1;
	}
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", d[j][i]);
		}
		printf("\n");
	}*/
	dfs(v, n);
	bfs(v, n);
	return 0;
}