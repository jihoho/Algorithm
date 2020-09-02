#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int tomato[100][100][100];
int visited[100][100][100];

typedef struct point{
    int x;
    int y;
    int z;
}Point;


Point dir[6]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};


int bfs(int m,int n,int h){
    // bfs 큐
    queue<point> q;

    // visited값 중 max 값에서 1을 뺀 값을 days로 지정하기 위한 변수
    int days=0;


    // 1(익은 토마토) 를 queue push, visited 1로 set
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tomato[i][j][k]==1){
                    q.push({k,j,i});
                    visited[i][j][k]=1;
                }
            }
        }
    }

    
    while(!q.empty()){

        Point cur=q.front();
        tomato[cur.z][cur.y][cur.x]=1;
        q.pop();

        for(int i=0;i<sizeof(dir)/sizeof(Point);i++){
            int next_x=cur.x+dir[i].x;
            int next_y=cur.y+dir[i].y;
            int next_z=cur.z+dir[i].z;
            // 인접한 next x,y,z 가 유효 범위 체크
            if(next_x>=0&&next_x<m&&next_y>=0&&next_y<n&&next_z>=0&&next_z<h){
                // next point의 값이 0(익지않은 토마토)이고, 방문하지 않은 경우
                if(!tomato[next_z][next_y][next_x]&&!visited[next_z][next_y][next_x]){
                    q.push({next_x,next_y,next_z});
                    // 현재 visited 값에 1 더함(depth 값 구하기 위해)
                    visited[next_z][next_y][next_x]=visited[cur.z][cur.y][cur.x]+1;
                }
            }

        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(days<visited[i][j][k]){
                    days=visited[i][j][k];
                }
                if(tomato[i][j][k]==0){
                    return -1;
                }
            }
        }
    }

    // 첫째날을 빼주어야함
    return days-1;
}




int main(){
    int m,n,h;
    memset(tomato,0,sizeof(tomato));
    
    cin>>m>>n>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>tomato[i][j][k];
            }
        }
    }

    cout<<bfs(m,n,h)<<endl;

    return 0;
}