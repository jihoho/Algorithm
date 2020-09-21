#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string, int> m;
    for (int i = 0; i < completion.size(); i++) {
        map<string, int>::iterator it = m.find(completion[i]);
        if (it == m.end()) {
            m.insert(pair<string, int>(completion[i], 1));
        }
        else {
            m[completion[i]] = m[completion[i]] + 1;
        }
    }
    for (int i = 0; i < participant.size(); i++) {
       
        map<string,int>::iterator it = m.find(participant[i]);
        if (it == m.end()) {
            answer = participant[i];
            break;
        }
        else {
            m[participant[i]] = m[participant[i]] - 1;
            if(m[participant[i]]==0)
                m.erase(it);
        }
    }
   
    return answer;
}

int main() {
    vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> completion={ "josipa", "filipa", "marina", "nikola"};
    cout<<"not complete "<< solution(participant, completion)<<endl;
}