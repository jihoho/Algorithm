#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
bool visited[10000];
vector<vector<string>> q;

void dfs(vector<vector<string>> tickets,vector<string> ans){
    
    if(ans.size()==tickets.size()+1){
        q.push_back(ans);
        return;
    }
    
    
    for(int i=0;i<tickets.size();i++){
        if(!visited[i]&&tickets[i][0]==ans[ans.size()-1]){
            ans.push_back(tickets[i][1]);
            visited[i]=true;
            dfs(tickets,ans);
            visited[i]=false;
            ans.pop_back();  
            
        }
        
    }
}

bool isdesc(vector<string> v1,vector<string> v2){
    for(int i=0;i<v1.size();i++){
        if(v1[i]>v2[i]){
            return false;
        }else if(v1[i]<v2[i]){
            return true;
        }
    }
    return true;
}

vector<string> dfsAll(vector<vector<string>> tickets){
    
    vector<string> result;
    vector<string> ans;
    string str1="ICN";
    ans.push_back(str1);
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]==str1&&!visited[i]){
            ans.push_back(tickets[i][1]);
            visited[i]=true;
            dfs(tickets,ans);
            visited[i]=false;
            ans.pop_back();  
        }
    }
    result=q[0];
    // for(int i=0;i<q.size();i++){
    //     for(int j=0;j<q[i].size();j++){
    //         cout<<q[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(int i=1;i<q.size();i++){
        if(!isdesc(result,q[i])){
            result=q[i];
        }
    }
    return result;
}
vector<string> solution(vector<vector<string>> tickets) {
   vector<string> answer;
   
    answer=dfsAll(tickets);
    return answer;
}