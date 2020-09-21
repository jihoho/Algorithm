#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++) {
        string cur = phone_book[i];
        for (int j = i+1; j < phone_book.size(); j++) {
            string next = phone_book[j];
            if (cur.length() > next.length()) {
                string sub = cur.substr(0, next.length());
                if (sub.compare(next) == 0) {
                    answer = false;
                    return answer;
                }
            }
            else {
                string sub = next.substr(0, cur.length());
                if (sub.compare(cur) == 0) {
                    answer = false;
                    return answer;
                }
            }

        }
    }
    answer = true;
    return answer;
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    cout << boolalpha << solution(phone_book) << endl;
    return 0;
}