#include<iostream>
using namespace std;
int recur(int n,int k){
    if(n==k||k==0){
        return 1;
    }
    return recur(n-1,k)+recur(n-1,k-1);
}
int main(){
    int n,k;
    cin >> n>>k;
    cout<<recur(n,k);
}