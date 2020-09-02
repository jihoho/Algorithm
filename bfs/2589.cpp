#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

char map[50][50];
int visited[50][50];

typedef struct point{
    int x;
    int y;
}Point;


Point dir[4]={{0,1},{0,-1},{1,0},{-1,0}};


int bfs(int m,int n,Point start){
    // bfs ť
    queue<point> q;

    q.push(start);
    visited[start.y][start.x]=1;

    int result=0;
   
    while(!q.empty()){

        Point cur=q.front();
        q.pop();

        for(int i=0;i<sizeof(dir)/sizeof(Point);i++){
            int next_x=cur.x+dir[i].x;
            int next_y=cur.y+dir[i].y;
            // ������ next x,y�� ��ȿ ���� üũ
            if(next_x>=0&&next_x<m&&next_y>=0&&next_y<n){
                // next point�� ���� L(����)�̰�, �湮���� ���� ���
                if(map[next_y][next_x]=='L'&&!visited[next_y][next_x]){
                    q.push({next_x,next_y});
                    // ���� visited ���� 1 ����(depth �� ���ϱ� ����)
                    visited[next_y][next_x]=visited[cur.y][cur.x]+1;
                    result=visited[next_y][next_x]-1>result?visited[next_y][next_x]-1:result;
                }
            }

        }
    }

 
    return result;
}

int bfsAll(int m,int n){
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (map[i][j]=='L'){
                memset(visited,0,sizeof(visited));
                int result=bfs(m,n,{j,i});
                max=result>max?result:max;
            }
        }
    }

    return max;
}



int main(){
    int m,n;
    memset(map,0,sizeof(map));
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    cout<<bfsAll(m,n)<<endl;

    return 0;
}