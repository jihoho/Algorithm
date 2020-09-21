#include <string>
#include <vector>
#include <cstring>
using namespace std;
int shortest_path(int m, int n,vector<vector<int>> puddles){
    int map[101][101];
    memset(map,0,sizeof(map));
    
    for(int i=0;i<puddles.size();i++){
        if(puddles[i][0]==1){
            for(int j=puddles[i][1];j<=n;j++){
                map[1][j]=-1;
            }
        }else if(puddles[i][1]==1){
            for(int j=puddles[i][0];j<=m;j++){
                map[j][1]=-1;
            }
        }else{
            map[puddles[i][0]][puddles[i][1]]=-1;
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==-1){
                map[i][j]=0;
            }else if(i==1||j==1){
                map[i][j]=1;
            }else {
                map[i][j]=(map[i-1][j]+map[i][j-1])%1000000007;
            }
        }
    }
    return map[m][n];
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    answer=shortest_path(m,n,puddles);
    return answer;
}