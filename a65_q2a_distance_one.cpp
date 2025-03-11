#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int re(int n,int k,vector<int> &table){
    if(n<=0){
        return 1;
    }
    if(table[n]!=-1){
        return table[n];
    }
    int t = (re(n-1,k,table)+re(n-k,k,table))%100000007;
    table[n] = t;
    return table[n];
}
int main(){
    int n,k;
    cin >> n>>k;
    vector<int> table(n+1,-1);
    table[0]=0;
    table[1] = 2;
    re(n,k,table);
    cout <<table[n];
}