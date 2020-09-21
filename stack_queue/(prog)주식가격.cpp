#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int cur = prices[i];
        int cnt = 0;
        for (int j = i+1; j < prices.size(); j++) {
            int next = prices[j];
            cnt++;
            if (cur > next) {
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main() {
    vector <int> pr = { 1, 2, 3, 2, 3 };
    vector <int> an = solution(pr);
    for (int i = 0; i < an.size(); i++) {
        printf("%d ", an[i]);
    }
    return 0;
}