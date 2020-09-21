#include <cstring>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
struct point {
    int x;
    int y;
};
char v[200];

void dfs(int n, int start, int num, vector<vector<int>> computers) {
    stack<int> s;
    s.push(start);
    v[start] = num;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (int i = 0; i < n; i++) {
            if (cur != i) {
                if (!v[i] && computers[cur][i]) {
                    s.push(cur);
                    s.push(i);
                    v[i] = num;
                    break;
                }
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(v, 0, sizeof(v));
    int clu = 1;
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            dfs(n, i, clu, computers);
            clu++;
        }
    }
    clu--;
    return clu;
}



int main() {
    vector<vector<int>> arr = { {1,1,0},{1,1,1},{0,1,1} };
    solution(3, arr);
}