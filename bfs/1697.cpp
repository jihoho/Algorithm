#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int visited[100001];


int bfs(int young,int brother){
    // bfs ť
    queue<int> q;
    q.push(young);
    visited[young]=1;
    // visited�� �� max ������ 1�� �� ���� days�� �����ϱ� ���� ����
    int time=0;

    
    while(!q.empty()){

        int cur=q.front();
        q.pop();

        if (cur==brother){
            return visited[cur]-1;
        }

        int next=cur-1;
        if(next>=0&&next<=100000&&!visited[next]){
            visited[next]=visited[cur]+1;
            q.push(next);
        }
        next=cur+1;
        if(next>=0&&next<=100000&&!visited[next]){
            visited[next]=visited[cur]+1;
            q.push(next);
        }
        next=cur*2;
        if(next>=0&&next<=100000&&!visited[next]){
            visited[next]=visited[cur]+1;
            q.push(next);
        }
        // cout<<endl;
    }

    return -1;
}




int main(){
    int y,o;
    cin>>y>>o;
    

    cout<<bfs(y,o)<<endl;

    return 0;
}