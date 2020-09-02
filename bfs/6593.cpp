#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

char building[30][30][30];
int visited[30][30][30];

typedef struct point{
    int x;
    int y;
    int z;
}Point;

Point dir[6]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};


int bfs(Point start,int l,int r,int c){
    // bfs 큐
    queue<point> q;


    memset(visited,0,sizeof(visited));

    // S(staring point) 를 queue push, visited 1로 set
    q.push({start.x,start.y,start.z});
    
    while(!q.empty()){

        Point cur=q.front();
        building[cur.z][cur.y][cur.x]=1;
        q.pop();

        for(int i=0;i<sizeof(dir)/sizeof(Point);i++){
            int next_x=cur.x+dir[i].x;
            int next_y=cur.y+dir[i].y;
            int next_z=cur.z+dir[i].z;
            // 인접한 next x,y,z 가 유효 범위 체크
            if(next_x>=0&&next_x<c&&next_y>=0&&next_y<r&&next_z>=0&&next_z<l){
                //방문하지 않은 경우
                if(!visited[next_z][next_y][next_x]){
                    // next point의 값 .(이동가능한 칸)일 경우   
                    if(building[next_z][next_y][next_x]=='.'){
                        q.push({next_x,next_y,next_z});
                        // 현재 visited 값에 1 더함(depth 값 구하기 위해)
                        visited[next_z][next_y][next_x]=visited[cur.z][cur.y][cur.x]+1;
                    }else if(building[next_z][next_y][next_x]=='E'){
                        // 탈출구 찾은 경우 visited값 (depth) 값 return
                        return visited[cur.z][cur.y][cur.x]+1;
                    }
                }
            }

        }
    }

    

    // 탈출하지 못한 경우
    return -1;
}




int main(){
    int L,R,C;
    memset(building,0,sizeof(building));
    vector<int> answer;
    cin>>L>>R>>C;    
    while(L!=0||R!=0||C!=0){
        Point start;
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    cin>>building[i][j][k];
                    if(building[i][j][k]=='S'){
                        start={k,j,i};
                    }
                }
            }
        }
        int result=bfs(start,L,R,C);
        answer.push_back(result);
        cin>>L>>R>>C;    
    }


    for(int i=0;i<answer.size();i++){
        if(answer[i]==-1){
            cout<<"Trapped!"<<endl;
        }else{
            cout<<"Escaped in "<<answer[i]<<" minute(s)."<<endl;
        }
    }

    return 0;
}


