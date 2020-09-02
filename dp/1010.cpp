#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int d[31][31];
struct node {
	int x; int y;
};

int ncr(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (d[n][r]) return d[n][r];
	return d[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
}
int main() {
	int n;
	int result;
	cin >> n;
	memset(d, 0, sizeof(d));
	node* test = new node[n];
	for (int i = 0; i < n; i++) {
		cin >> test[i].x >> test[i].y;
	}
	for (int i = 0; i < n; i++) {
		result = ncr(test[i].y, test[i].x);
		cout << result << endl;
	}
	
	delete[] test;
}