#include <iostream>
#include <queue>
using namespace std;
int n;
int k;
int arr[101][101];
int l;
int cur = 1;
struct snake {
	int x; int y;
};

queue <snake> q;

struct node {
	int x; char c;
};


int simul(int *x,int *y) {
	int a, b;
	snake s;
	if (cur == 1) {
		a = *x, b = *y + 1;
		if (b > n||arr[a][b]==1) {
			return -1;
		}
		
		if (arr[a][b] != 7) {
			arr[q.front().x][q.front().y] = 0;
			q.pop();
		}
		s.x = a, s.y = b;
		q.push(s);
		arr[a][b] = 1;
		
		*x = a, *y = b;
	}
	else if (cur == 2) {
		a = *x+1, b = *y;
		if (a > n || arr[a][b] == 1) {
			return -1;
		}
		if (arr[a][b] != 7) {
			arr[q.front().x][q.front().y] = 0;
			q.pop();
		}
		s.x = a, s.y = b;
		q.push(s);
		arr[a][b] = 1;
		
		*x = a, * y = b;
	}
	else if (cur == 3) {
		a = *x, b = *y-1;
		if (b < 1 || arr[a][b] == 1) {
			return -1;
		}
		if (arr[a][b] != 7) {
			arr[q.front().x][q.front().y] = 0;
			q.pop();
		}
		s.x = a, s.y = b;
		q.push(s);
		arr[a][b] = 1;
		
		*x = a, * y = b;
	}
	else if (cur == 4) {
		a = *x-1, b = *y;
		if (a < 1 || arr[a][b] == 1) {
			return -1;
		}
		if (arr[a][b] != 7) {
			arr[q.front().x][q.front().y] = 0;
			q.pop();
		}
		s.x = a, s.y = b;
		q.push(s);
		arr[a][b] = 1;
		
		*x = a, * y = b;
	}
	//cout << "!!!!" << a << "," << b << endl;
	return 0;
}
int main() {
	int i;
	int x, y;
	int time=0;
	int check=0;
	int result;
	node dir[100];
	cin >> n >> k;
	for (i = 0; i < k; i++) {
		cin >> x >> y;
		arr[x][y] = 7;
	}
	cin >> l;
	for (i = 0; i < l; i++) {
		cin >> dir[i].x >> dir[i].c;

	}
	snake s = { 1,1 };
	arr[1][1] = 1;
	q.push(s);
	
	x = 1; y = 1;
	while (1) {
		
		if (dir[check].x == time && check < l) {
			if (dir[check].c == 'L') {
				if (cur - 1 > 0)
					cur--;
				else
					cur = 4;
			}
			else {
				if (cur + 1 < 5) {
					cur++;
				}
				else
					cur = 1;
			}
			check++;
		}
		time++;
		result=simul(&x, &y);
		if (result == -1) {

			cout << time << endl;
			return 0;
		}

	
		
		
	}
	return 0;
}