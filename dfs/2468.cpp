#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int matrix[100][100];
bool test[100][100];
bool visited[100][100];
int max_h=0;

typedef struct point{
    int x;
    int y;
}Point;


Point dir[4]={{0,1},{0,-1},{1,0},{-1,0}};


void dfs(int x,int y,int n){
    // cout<< "DFS visited "<<x<<","<<y<<endl;-
    visited[x][y]=true;

    // ��� ���� ������ ��ȸ�ϸ鼭
    for(int i=0;i<sizeof(dir)/sizeof(Point);i++){

        int next_x=x+dir[i].x;
        int next_y=y+dir[i].y;

        if(next_x>=0&&next_x<n&&next_y>=0&&next_y<n){
            if(!visited[next_x][next_y]&&test[next_x][next_y])
                dfs(next_x,next_y,n);
        }
    }
    
    // �� �̻� �湮�� ������ ������, ��� ȣ�� �����ϰ� ���� �������� ���ư�
}

//  ���� ���� ����
int dfsAll(int n){
    int cnt=0;
    //��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]&&test[i][j]==1){
                // cout<< "fisrt point "<<x<<","<<y<<endl;
                dfs(i,j,n);
                cnt++;
            }
        }
    }
    return cnt;
}

// ħ�� ���� ���� ���� 1�� set
void submerge(int n,int h){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]>h)
                test[i][j]=1;
        }
    }
}

// ���̰� 0���� �ǹ��� �ִ� ���̱��� ���� ��� ��� ����
int simulation(int n){
    int max=0;
    for(int i=0;i<max_h;i++){
        memset(test,0,sizeof(test));
        memset(visited,0,sizeof(visited));
        submerge(n,i);
        int result=dfsAll(n);
        max=result>max?result:max;
    }
    return max;
}

int main(){
    int n;
    

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
            max_h=matrix[i][j]>max_h?matrix[i][j]:max_h;
        }
    }

    cout<<simulation(n)<<endl;

    return 0;
}