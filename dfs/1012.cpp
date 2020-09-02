#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// 그래프의 인접 리스트 표현
bool adj[50][50];

// 각 정점을 방문했는지 여부를 나타냄
bool visited[50][50];

struct point{
    int x;
    int y;
};

struct point p[4]={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x,int y,int m,int n){
    // cout<< "DFS visited "<<x<<","<<y<<endl;
    visited[y][x]=true;


    // 모든 인접 정점을 순회하면서
    for(int i=0;i<sizeof(p)/sizeof(struct point);i++){

        int next_x=x+p[i].x;
        int next_y=y+p[i].y;

        if(next_x>=0&&next_x<m&&next_y>=0&&next_y<n){
            if((!visited[next_y][next_x])&&adj[next_y][next_x])
                dfs(next_x,next_y,m,n);
        }
    }
    
    // 더 이상 방문한 정점이 없으니, 재귀 호출 종료하고 이전 정점으로 돌아감
}


int dfsAll(int m,int n){
    int cnt=0;
    
    //모든 정점을 순회하면서, 아직 방문한 적 없으면 방문
    for(int y=0; y<n;y++){
        for(int x=0;x<m;x++){
            if(!visited[y][x]&&adj[y][x]){
                // cout<< "fisrt point "<<x<<","<<y<<endl;
                dfs(x,y,m,n);
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    vector<int> answer;
    int t;
    cin>>t;

    
    for(int i=0;i<t;i++){
        int m,n,k;
        cin>>m>>n>>k;

        memset(adj,false,sizeof(adj));
        memset(visited,false,sizeof(visited));

        for(int j=0;j<k;j++){
            int x,y;
            cin>>x>>y;
            adj[y][x]=true;
        }
       
        int result=dfsAll(m,n);
        answer.push_back(result);
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}