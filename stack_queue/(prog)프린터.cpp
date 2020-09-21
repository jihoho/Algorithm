#include <string>
#include <vector>
#include <queue>
using namespace std;

struct _data {
    int idx;
    int value;
};
int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector <_data> v;

    for (int i = 0; i < priorities.size(); i++) {
        _data d = { i,priorities[i] };
        v.push_back(d);
    }

    vector<_data> ::iterator iter = v.begin();
    int cnt = 0;
    while (!v.empty()) {
        _data cur = v[0];
        printf("cur idx: %d, value: %d\n", cur.idx,cur.value);
        iter = v.begin();
        v.erase(iter);
        int check = 0;
        for (int i = 0; i < v.size(); i++) {
            printf("%d ", v[i].value);
        }
        printf("\n");
        for (int i = 0; i < v.size(); i++) {
            if (cur.value < v[i].value) {
                check = 1;
                break;
            }
        }
        if (check) {
            v.push_back(cur);
            printf("push back\n");
        }
        else {
            cnt += 1;
            printf("print %d\n", cnt);
            if (cur.idx == location) {
                break;
            }
        }
    }
    answer = cnt;
    return answer;
}

int main() {
    vector<int> v = { 1, 1, 9, 1, 1, 1 };
    printf("%d", solution(v, 0));
}