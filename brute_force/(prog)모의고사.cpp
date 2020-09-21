#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> patt={{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    vector<int> peo={0,0,0};
    for(int i=0;i<answers.size();i++){
        if(i==0){
            for(int j=0;j<peo.size();j++){
                if(answers[i]==patt[j][i]){
                    peo[j]+=1;
                }
            }   
        }else{
            for(int j=0;j<peo.size();j++){
                if(answers[i]==patt[j][i%patt[j].size()]){
                    peo[j]+=1;
                }
            }
        } 
    }
    for(int i=0;i<3;i++){
        printf("%d ",peo[i]);
    }
    int max=peo[0]>peo[1]?peo[0]:peo[1];
    max=peo[2]>max?peo[2]:max;
    printf("\nmax  :%d",max);
    for(int i=0;i<3;i++){
        if(max==peo[i]){
            answer.push_back(i+1);
        }
    }                       
    return answer;
}