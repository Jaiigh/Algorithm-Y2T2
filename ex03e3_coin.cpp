#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int re(int a,int b){

// }
int main(){
    int n,price;
    cin >> n >> price;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
   sort(a.begin(),a.end());
    vector<vector<int>> table(n+1,vector<int>(price+1));
    
    for(int i=0;i<=n;i++){
        table[i][0]=0;
    }
    for(int i=0;i<=price;i++){
        table[0][price]=0;
        table[1][i] = i;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=price;j++){
            if(a[i]>j){
                table[i][j] = table[i-1][j];
            }else{
                table[i][j] = min(table[i-1][j],table[i][j-a[i]]+1);
        }
    }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=price;j++){
            cout<<table[i][j]<<" ";
    }
    cout <<"\n";
    }

    cout <<table[n][price];
    
}