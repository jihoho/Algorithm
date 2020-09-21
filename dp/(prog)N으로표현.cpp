#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

set<int> calc_set(set<int> a,set<int> b){
    set<int> result;
    for(set<int>::iterator it_a=a.begin();it_a!=a.end();it_a++){
        for(set<int>::iterator it_b=b.begin();it_b!=b.end();it_b++){
    
            result.insert(*it_a + *it_b);
            
            result.insert(*it_a - *it_b);
            result.insert(*it_b - *it_a);
            result.insert(*it_a * *it_b);
            if(*it_b!=0)
                result.insert((int)*it_a / *it_b);
            if(*it_a!=0)
                result.insert((int)*it_b / *it_a);
        
        }
    }
    return result;
}

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>> v;
    set<int> s;
    s.insert(N);
    v.push_back(s);
    v.push_back(s);
    for(int i=2;i<=8;i++ ){
        set<int> s;
        int num=0;
        for(int j=i-1;j>=0;j--){
            num+=N*pow(10,j);
        }
        s.insert(num);
        for(int j=1;j<=i/2;j++){
            set<int> a=v[j];
            set<int> b=v[i-j];
            set<int> c=calc_set(a,b);
            cout<<"("<<j<<","<<i-j<<") ";
            
            set_union(s.begin(), s.end(), c.begin(), c.end(), inserter(s, s.begin()));

        }
        
        
        cout<<i<<"¹ø set  ";
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        v.push_back(s);
    }
    
    for(int i=1;i<v.size();i++){
        set<int> s=v[i];
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            if(*it==number){
                return i;
            }
        }
    }
    return -1;
}