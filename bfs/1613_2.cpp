#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include <cstdio>
using namespace std;

typedef struct point{
    int x;
    int y;
}Point;


int m[401][401];
Point arr[401*401];

void solution(int n,int s){
    // for(int i=0;i<s;i++){
    //     for(int j=i+1;j<s;j++){
    //         if(arr[i].y==arr[j].x&&!m[arr[i].x][arr[j].y]){
    //            m[arr[i].x][arr[j].y]=1;
    //            arr[s]={arr[i].x,arr[j].y};
    //            s++;
    //         }
    //     }
    // }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][k]&&m[k][j]){
               m[i][j]=1;
            //    v.push_back({v[i].x,v[j].y});
            }
        }
    }
    
}




void print_m(int m[][401],int n){
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           cout<<m[i][j]<<" ";
       }
        cout<<endl;
    }
}



int main(){
    int n,k,s;
    vector<int> answer;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int c1,c2;
        cin>>c1>>c2;
        m[c1][c2]=1;
        arr[i]={c1,c2};
    }
    solution(n,k);
    
    cin>>s;
    for(int i=0;i<s;i++){
        int c1,c2;
        cin>>c1>>c2;
        int result=m[c1][c2];
        if(result){
            answer.push_back(-1);
        }else{
            result=m[c2][c1];
            if(result){
                answer.push_back(1);
            }else{
                answer.push_back(0);
            }
        }
    }

    for(int i=0;i<answer.size();i++){

        // printf("%d\n",answer[i]);
        cout<<answer[i]<<endl;
    }

    return 0;
}