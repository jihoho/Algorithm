#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int map[100][100];
int visited[100][100];

typedef struct point{
    int x;
    int y;
}Point;


Point dir[4]={{0,1},{0,-1},{1,0},{-1,0}};


int bfs_section(Point start,int n,int lnum){
    // bfs 큐
    queue<Point> q;
    
    Point dir[4]={{0,1},{0,-1},{1,0},{-1,0}};
    q.push(start);
    visited[start.y][start.x]=1;
    map[start.y][start.x]=lnum;
    while(!q.empty()){

        Point cur=q.front();
        q.pop();

        for (int i=0;i<sizeof(dir)/sizeof(Point);i++){
            int next_x=cur.x+dir[i].x;
            int next_y=cur.y+dir[i].y;
            // 인접한 next 가 유효 범위 체크
             if(next_x>=0&&next_x<n&&next_y>=0&&next_y<n){
                // next point의 값이 1(육지)이고, 방문하지 않은 경우
                if(!visited[next_y][next_x]&&map[next_y][next_x]){
                    q.push({next_x,next_y});
                    visited[next_y][next_x]=1;
                    map[next_y][next_x]=lnum;
                }
            }
        }
    }

 
    return -1;
}


int sectioning(int n){
    int lnum=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]&&!visited[i][j]){
                bfs_section({j,i},n,lnum);
                lnum++;
            }
        }
    }

    // cout<<lnum-1<<endl;

    return lnum-1;
}

void print_map(int n,int arr[][100]){
    
    cout<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int find_dis(int lnum1,int n){
    int min=100*100;
    Point dir[4]={{0,1},{0,-1},{1,0},{-1,0}};
     // bfs 큐
    memset(visited,0,sizeof(visited));  
    queue<Point> q;
    Point start;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==lnum1){
                start={j,i};
                q.push(start); 
                
                visited[start.y][start.x]=1;
               
            }
        }
    }
    
    // print_map(n,visited);

    while(!q.empty()){

        Point cur=q.front();
        q.pop();
        // cout<<"cur ("<<cur.x<<","<<cur.y<<")"<<endl;
        for (int i=0;i<sizeof(dir)/sizeof(Point);i++){
            int next_x=cur.x+dir[i].x;
            int next_y=cur.y+dir[i].y;
            
            // 인접한 next 가 유효 범위 체크
            if(next_x>=0&&next_x<n&&next_y>=0&&next_y<n){
                // next point의 값이 0(해안)이고, 방문하지 않은 경우
                if(!visited[next_y][next_x]){
                    if(map[next_y][next_x]==0){
                        q.push({next_x,next_y});
                        visited[next_y][next_x]=visited[cur.y][cur.x]+1;
                        // cout<<"next ("<<next_x<<","<<next_y<<")"<<endl;
                        // print_map(n,visited);
                    }else if(map[next_y][next_x]!=lnum1){
                        
                        // print_map(n,visited);
                        return visited[cur.y][cur.x]-1;
                    }
                }
            }
        }
    }

}


int solution(int n){
    int sect=sectioning(n);
    // print_map(n,map);
    int min=100*100;
    for(int i=1;i<=sect;i++){
        int result=find_dis(i,n);
        // cout<<i<<" result: "<<result<<endl;
        min=min>result?result:min;
    }
    // cout<<"min: "<<min<<endl;
    return min;
}
int main(){
    int n;
    memset(visited,0,sizeof(visited));
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    int result=solution(n);
    cout<<result<<endl;;

    return 0;
}
