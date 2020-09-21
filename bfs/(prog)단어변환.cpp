#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int visited[50];
bool check_word(string str1,string str2){
    int check=0;
    
    for(int i=0;i<str1.length();i++){
        if(str1[i]!=str2[i]){
            check++;
            if(check>1){
                return false;
            }
        }
    }
    return true;
    
}
int bfs(vector<string> words,string begin,string target){
    int result=0;
    queue<int> q;
    int start;
    for(int i=0;i<words.size();i++){
        if(words[i]==begin){
            start=i;
            break;
        }
    }
    q.push(start);
    memset(visited,0,sizeof(visited));
    visited[start]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        printf("\n----%d(visited=%d)\n",cur,visited[cur]);
        if(words[cur]==target){
            result=visited[cur]-1;
            printf("result %d" ,result);
            break;
        }
        for(int i=0;i<words.size();i++){
            if(!visited[i]){
                if(check_word(words[cur],words[i])){
                    
                    visited[i]=visited[cur]+1;
                    printf("next=%d,visited=%d  ",i,visited[i]);
                    q.push(i);
                }
            }
        }
    }
    return result;
    
    
}
int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    int answer = bfs(words,begin,target);
    return answer;
}