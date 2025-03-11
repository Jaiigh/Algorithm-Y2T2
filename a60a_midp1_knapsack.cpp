#include <iostream>
#include <vector>
using namespace std;
void re(int a,int b,vector<int> &V,vector<int> &W,vector<vector<int>> &table,vector<int> &result){

    if(a==0||b==0){
        return ;
    }
    if(b>=W[a]&&a>0){
        if(table[a-1][b]>=table[a-1][b-W[a]]+V[a]){
            re(a-1,b,V,W,table,result);
            return ;
        }else{
            result.push_back(a);
            re(a-1,b-W[a],V,W,table,result);
            return ;
        }
        return;
    }else{
        re(a-1,b,V,W,table,result);
        return;
    }
}
int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n,m;
    cin >> n >>m;
    vector<int> V(n+1),W(n+1);
    for(int i=1;i<=n;i++){
        cin >> V[i];
    }
    for(int i=1;i<=n;i++){
        cin >> W[i];
    }
    vector<vector<int>> table(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        //cout<<"start i"<<i<<"\n";
        for(int j=0;j<=m ;j++){
            cin >> table[i][j];
        }
        //cout<<"end i"<<i<<"\n";
    }
    //cout<<"end"<<"\n";
    vector<int> result ;
    re(n,m,V,W,table,result);
    int si = result.size();
    cout<< si<<"\n";
    for(int i=si-1;i>=0;i--){
        cout<<result[i]<<" ";
    }
}