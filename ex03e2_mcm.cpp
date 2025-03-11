
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int mcm(int l,int r,vector<vector<int>> &table,vector<int> &a){
    if(l>=r){
        return 0;
    }
    if(table[l][r]!=-1){
        return table[l][r];
    }else {
      
        int mi = INT_MAX;
        for(int i=l;i<r;i++){
            int  t = mcm(l,i,table,a) + mcm(i+1,r,table,a) + a[l-1]*a[i]*a[r];
            if(mi>t){
                mi = t;
            }
        }
        table[l][r] = mi;
        return table[l][r];
    }
    
}
int main(){
    int n;
    cin>> n;
    vector<vector<int>> table(n+1,vector<int>(n+1,-1));
    vector<int> a(n+1);
    for(int i=0;i<=n;i++){
        cin >>a[i];
        //cout<<"size="<<a[i]<<"\n";
    }
    cout <<mcm(1,n,table,a);
}

// int mcm(int l, int r, vector<vector<int>> &table, vector<int> &S) {
//     if (l >= r) {
//         return 0;
//     } else {
//         if(table[l][r] != -1) {
//             return table[l][r];
//         }

//         int mincost = INT_MAX;
//         for(int i = l;i < r;i++){
//             int cost = mcm(l,i,table,S) + mcm(i+1,r,table,S) + (S[l-1] * S[i] * S[r]);
//             mincost = min(mincost,cost); 
//         }
//         table[l][r] = mincost;
//         return mincost;
//     }
// }

// int main() {
//     int N;cin >> N;
//     vector<int> S(N+1);
//     for(int i = 0;i < (N+1);i++){
//         cin >> S[i];
//     }
//     vector<vector<int>> table(N + 1,vector<int>(N + 1,-1));
//     cout << mcm(1, N, table, S);
// }