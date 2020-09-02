#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int visited[1000001];




// f: 건물 총 높이, s: 강호가 있는 층, g: 스타트링크가 있는 층, u: 위로 이동 수, d:아래로 이동 수
int bfs(int f,int s,int g, int u, int d){
    // bfs 큐
    queue<int> q;

    q.push(s);
    visited[s]=1;
    int dir[2]={u,-d};
   
    while(!q.empty()){

        int cur=q.front();
        q.pop();

        for (int i=0;i<sizeof(dir)/sizeof(int);i++){
            int next=cur+dir[i];
                // 인접한 next 가 유효 범위 체크
            if(next>=1&&next<=f){
                // next point의 값이 L(육지)이고, 방문하지 않은 경우
                if(!visited[next]){
                    q.push(next);
                    // 현재 visited 값에 1 더함(depth 값 구하기 위해)
                    visited[next]=visited[cur]+1;
                    if(next==g){
                        return visited[next]-1;
                    }
                }
            }
        }
    }

 
    return -1;
}





int main(){
    int f,s,g,u,d;
    memset(visited,0,sizeof(visited));
    
    cin>>f>>s>>g>>u>>d;
    int result=bfs(f,s,g,u,d);
    if(s==g){
        cout<<0<<endl;
    }
    else if(result<0){
        cout<<"use the stairs"<<endl;
    }else{
        cout<<result<<endl;
    }

    return 0;
}