#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// �׷����� ���� ����Ʈ ǥ��
bool adj[50][50];

// �� ������ �湮�ߴ��� ���θ� ��Ÿ��
bool visited[50][50];

struct point{
    int x;
    int y;
};

struct point p[4]={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x,int y,int m,int n){
    // cout<< "DFS visited "<<x<<","<<y<<endl;
    visited[y][x]=true;


    // ��� ���� ������ ��ȸ�ϸ鼭
    for(int i=0;i<sizeof(p)/sizeof(struct point);i++){

        int next_x=x+p[i].x;
        int next_y=y+p[i].y;

        if(next_x>=0&&next_x<m&&next_y>=0&&next_y<n){
            if((!visited[next_y][next_x])&&adj[next_y][next_x])
                dfs(next_x,next_y,m,n);
        }
    }
    
    // �� �̻� �湮�� ������ ������, ��� ȣ�� �����ϰ� ���� �������� ���ư�
}


int dfsAll(int m,int n){
    int cnt=0;
    
    //��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮
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