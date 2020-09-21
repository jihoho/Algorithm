#include <string>
#include <vector>
#include <queue>

using namespace std;
struct car{
    int w;
    int d;
};
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector <car> q;
    int time=1;
    car c;
    c.w=truck_weights[0];
    c.d=1;
    truck_weights.erase(truck_weights.begin());
    q.push_back(c);
    while(!q.empty()){
        // printf("%d ",time);
        // for(int i=0;i<q.size();i++){
        //     printf("(w:%d d:%d) ",q[i].w,q[i].d);
        // }
        int sum_w=0;
        if(q[0].d>=bridge_length){
            q.erase(q.begin());
        }
        for(int i=0;i<q.size();i++){
            q[i].d+=1;
            sum_w+=q[i].w;
        }
        if(!truck_weights.empty()){
            if(sum_w +truck_weights[0]<= weight){
                car c={truck_weights[0],1};
                truck_weights.erase(truck_weights.begin());
                q.push_back(c);
            }
        }
      
        
        time+=1;
       
        // printf("\n");
    }
    answer=time;
    return answer;
}