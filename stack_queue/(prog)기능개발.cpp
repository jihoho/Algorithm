// ������ ����Ǿ����ϴ�. �̷� ���� �Լ� �����̳� �׽�Ʈ���̽��� ����Ǿ�, ������ �ڵ�� �������� ���� �� �ֽ��ϴ�.
// ���ο� �Լ� ������ �����Ϸ��� [�ڵ� �ʱ�ȭ] ��ư�� ��������. ��, [�ڵ� �ʱ�ȭ] ��ư�� ������ �ۼ� ���� �ڵ�� ������ϴ�.
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