#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
multimap <int,int> mm;
int visited[401];
int m[41][41];

int bfs(int n,int case1,int case2){
    // bfs 큐
    queue<int> q;
    q.push(case1);
    memset(visited,0,sizeof(visited));
    visited[case1]=1;
    int check=0;
    
    multimap <int,int>::iterator iter;
    
    while(!q.empty()){

        int cur=q.front();
        q.pop();

        if (cur==case2){
            check=-1;
            break;
        }
        iter=mm.lower_bound(cur);
        // cout<<"cur "<<cur<<endl;
        while(iter!=mm.upper_bound(cur)&&!visited[iter->second]){
            visited[iter->second]=1;
            mm.insert(pair<int,int>(cur,iter->second));
            // cout<<"정방향 "<<iter->second<<endl;   
            q.push(iter->second);
            iter++;
        }

    }
    
    if(check==0){
        memset(visited,0,sizeof(visited));
        visited[case2]=1;
        // cout<<"check 0"<<endl;
        queue<int> q;
        q.push(case2);
        
        while(!q.empty()){

            int cur=q.front();
            q.pop();

            if (cur==case1){
                check=1;
                break;
            }
            iter=mm.lower_bound(cur);
            // cout<<"cur "<<cur<<endl;
            while(iter!=mm.upper_bound(cur)&&!visited[iter->second]){
                // cout<<"역방향 "<<iter->second<<endl;
                mm.insert(pair<int,int>(cur,iter->second));
                visited[iter->second]=1;
                q.push(iter->second);
                iter++;
            }
        }
    }
    return check;
}




int main(){
    int n,k,s;
    vector<int> answer;
    cin>>n>>k;

    for(int i=0;i<k;i++){
        int c1,c2;
        cin>>c1>>c2;
        mm.insert(pair<int,int>(c1,c2));
    }
    cin>>s;
    for(int i=0;i<s;i++){
        int c1,c2;
        cin>>c1>>c2;
        answer.push_back(bfs(n,c1,c2));

    }

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}