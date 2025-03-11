// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <limits.h>
// using namespace std;

// int main(){
//     int n,k;
//     cin >> n >>k;
//     vector<int> a(n+1),b(k+1),table(n+1,INT_MIN);
//     for(int i=1;i<=n;i++){
//         cin >> a[i];
//     }
//     for(int i=1;i<=k;i++){
//         cin >> b[i];
//     }
//     table[1] = a[1];
//     for(int i=2;i<=n;i++){
//         for(int j=1;j<=k;j++){
//             if(i-j>0){
//                 table[i] = max(table[i],table[i-j]-b[j]+a[i]);
//                 cout << "table[i=]"<<table[i]<<"\n";
//                 cout << table[i-j]-b[j]+a[i]<<"\n";
//             }
            
//         }
//     }
//     cout <<table[n];
    
// }
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int recur(int n,int k,vector<int> &a,vector<int> &b,vector<int> &table){
    if(table[n]!=INT_MIN){
        return table[n];
    }
    if(n==1){
        table[1] = a[1];
        return table[1];
    }

    for(int i = 1;i<=k;i++){
        if(n-i>0){
            table[n] = max(table[n],recur(n-i,k,a,b,table)-b[i]+a[n]);
        }
        
    }
    return table[n];
}
int main(){
    int n,k;
    cin >> n >>k;
    vector<int> a(n+1),b(k+1),table(n+1,INT_MIN);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=k;i++){
        cin >> b[i];
    }
    cout << recur(n,k,a,b,table);
}