#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int matrix[8][8];
int test[8][8];

typedef struct point{
    int x;
    int y;
}Point;

// zero ���� vector�� �����ϱ� ���� ����
vector<Point> zero;

// ���̷��� ������ ���� ����
Point dir[4]={{0,1},{0,-1},{1,0},{-1,0}};


void dfs(int x,int y,int n,int m){
    // cout<< "DFS visited "<<x<<","<<y<<endl;
    test[x][y]=2;


    // ��� ���� ������ ��ȸ�ϸ鼭
    for(int i=0;i<sizeof(dir)/sizeof(Point);i++){

        int next_x=x+dir[i].x;
        int next_y=y+dir[i].y;

        if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m){
            if(!test[next_x][next_y])
                dfs(next_x,next_y,n,m);
        }
    }
    
    // �� �̻� �湮�� ������ ������, ��� ȣ�� �����ϰ� ���� �������� ���ư�
}

// ���̷��� ���� dfs
void dfsAll(int n,int m){
    
    //��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(test[i][j]==2){
                // cout<< "fisrt point "<<x<<","<<y<<endl;
                dfs(i,j,n,m);
            }
        }
    }
}

// �࿭ ���
void print_matrix(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
}


// ���̷����� ���� ���� ���� ���� ����
int check_safe(int n,int m){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!test[i][j])
                cnt++;
        }
    }
    return cnt;
}


// �� 3���� ���� �� dfs ���� �� ���� ���� ���� Ȯ��
int simulation(int n,int m){
    int max=0;
    for(int i=0;i<zero.size();i++){
        for(int j=i+1;j<zero.size();j++){
            for(int k=j+1;k<zero.size();k++){
                memcpy(test,matrix,sizeof(matrix));
                test[zero[i].x][zero[i].y]=3;
                test[zero[j].x][zero[j].y]=3;
                test[zero[k].x][zero[k].y]=3;
                // cout<<"**********before infection"<<endl;
                // print_matrix(n,m);
                dfsAll(n,m);
                // cout<<"**********after infection"<<endl;
                // print_matrix(n,m);
                int safe_cnt=check_safe(n,m);
                max=safe_cnt>max?safe_cnt:max;
            }   
        }   
    }

    return max;
}






int main(){
    int n,m;
    cin>>n>>m;
    memset(matrix,0,sizeof(matrix));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            if(!matrix[i][j]){
                Point p={i,j};
                zero.push_back(p);
        
            }
        }
    }
    // cout<<zero.size()<<endl;
    // for(int i=0;i<zero.size();i++){
    //     cout<<zero[i].x<<","<<zero[i].y<<endl;
    // }
    
    cout<<simulation(n,m)<<endl;
    return 0;
}