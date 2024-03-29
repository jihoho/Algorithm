// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> _time;
    for(int i=0;i<progresses.size();i++){
        int pr=progresses[i];
        int spd=speeds[i];
        int days=(100-pr)/spd;
        _time.push_back(days);
    }
    int i,j;
    for (i=0;i<_time.size();){
        int cur_t=_time[i];
        for (j=i+1;j<_time.size();j++){
            int next_t=_time[j];
            if (next_t>cur_t){
                break;
            }
        }
        answer.push_back(j-i);
        i=j;
    }
    return answer;
}