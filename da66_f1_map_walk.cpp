#include <iostream>
#include <vector>
using namespace std;
int x,y;
string res;
void recur(int posx,int posy,vector<vector<int>> map,bool useb,bool usec){
    
    if(posx==0 || posy==0){
        return;
    }
    if(posx==x+1||posy==y+1){
        return ;
    }
    if(map[posy-1][posx-1]==1){
        return ;
    }
    if(posx==x && posy==y){
        
        cout << res<<"\n";
        return ;
    }
    res.push_back('A');
    recur(posx+1,posy,map,false,false);
    res.pop_back();
    if(usec==false){
        res.push_back('B');
        recur(posx,posy+1,map,true,usec);
        res.pop_back();
    }
    if(useb==false){
        res.push_back('C');
        recur(posx,posy-1,map,useb,true);
        res.pop_back();
    }
    
}
int main(){
    cin >> y>>x;
    string s;
    vector<vector<int>> m;
    int t;
    // int m[y][x];
    for(int i=0;i<y;i++){
        vector<int> tmp;
        for(int j=0;j<x;j++){
        cin >> t;
        tmp.push_back(t);
    }
    m.push_back(tmp);
    }
    recur(1,1,m,false,false);
    cout <<"DONE";

}