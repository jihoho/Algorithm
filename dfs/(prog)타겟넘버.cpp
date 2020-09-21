#include <string>
#include <vector>

using namespace std;
int answer=0;
void dfs(vector<int> numbers,int index,int _sum,int target){
    int next;
    int result;
    if(index==numbers.size()){
        if(_sum==target){
            answer++;
        }
    }else{
        result=_sum+numbers[index];
        dfs(numbers,index+1,result,target);
        result=_sum-numbers[index];
        dfs(numbers,index+1,result,target);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,0,0,target);
    return answer;
}