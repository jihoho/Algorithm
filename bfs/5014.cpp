#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int visited[1000001];




// f: �ǹ� �� ����, s: ��ȣ�� �ִ� ��, g: ��ŸƮ��ũ�� �ִ� ��, u: ���� �̵� ��, d:�Ʒ��� �̵� ��
int bfs(int f,int s,int g, int u, int d){
    // bfs ť
    queue<int> q;

    q.push(s);
    visited[s]=1;
    int dir[2]={u,-d};
   
    while(!q.empty()){

        int cur=q.front();
        q.pop();

        for (int i=0;i<sizeof(dir)/sizeof(int);i++){
            int next=cur+dir[i];
                // ������ next �� ��ȿ ���� üũ
            if(next>=1&&next<=f){
                // next point�� ���� L(����)�̰�, �湮���� ���� ���
                if(!visited[next]){
                    q.push(next);
                    // ���� visited ���� 1 ����(depth �� ���ϱ� ����)
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