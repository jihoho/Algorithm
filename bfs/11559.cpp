#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char m[13][7];
bool v[13][7];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;

void fall(int x, int y)
{
	char color = m[x][y];
	m[x][y] = '.';
	while (1) {
		x++;
		if (x > 12 || m[x][y] != '.') {
			m[x - 1][y] = color;
			break;
		}
	}
}
void reorganize(vector< pair<int, int> > &tmp)
{
	int x, y;
	for (int i = 0; i < tmp.size(); i++) {
		x = tmp[i].first, y = tmp[i].second;
		for (int tx = x; tx > 0; tx--) {
			if (m[tx][y] != '.') fall(tx, y);
		}
	}
}
bool bfs()
{
	int x, y, tx, ty, cnt;
	char color;
	bool flag = false;
	queue< pair<int, int> > q;
	vector< pair<int, int> > select;
	vector< pair<int, int> > tmp;

	memset(v, false, sizeof(v));

	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			if (!v[i][j] && (m[i][j] != '.')) {
				cnt = 1, select.clear();
				color = m[i][j], v[i][j] = true, q.push(make_pair(i, j)), select.push_back(make_pair(i, j));
				while (!q.empty()) {
					x = q.front().first, y = q.front().second, q.pop();
					for (int d = 0; d < 4; d++) {
						tx = x + dx[d], ty = y + dy[d];
						if (tx < 1 || tx > 12 || ty < 1 || ty > 6 || v[tx][ty] || m[tx][ty] != color) continue;
						cnt++, v[tx][ty] = true, q.push(make_pair(tx, ty)), select.push_back(make_pair(tx, ty));
					}
				}
				if (cnt >= 4) {
					int r, c;
					flag = true;
					for (int i = 0; i < select.size(); i++) {
						r = select[i].first, c = select[i].second;
						m[r][c] = '.';
						r -= 1;
						if (r >= 1) tmp.push_back(make_pair(r, c));
					}
				}
			}
		}
	}
	if (tmp.size() > 0) reorganize(tmp);
	return flag;
}
int main()
{
	char line[7];
	for (int i = 1; i <= 12; i++) {
		scanf("%s", &line);
		for (int j = 1; j <= 6; j++) {
			m[i][j] = line[j - 1];
		}
	}
	while (1) {
		if (bfs()) ans++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}


