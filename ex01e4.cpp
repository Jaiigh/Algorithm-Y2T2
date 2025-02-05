#include <iostream>
#include <vector>
using namespace std;
int recur(int a, int n,int k){
    if(n==1){
        return a%k;
    }
    if(n%2==0){
        int tmp =  recur(a,n/2,k);
        return (tmp*tmp) % k;
    }else {
        int tmp =  recur(a,n/2,k);
        tmp = (tmp*tmp) % k;
        return (tmp* (a%k)) %k;
    }
}
int main(){
    int a,n,k;
    cin >> a >> n >> k;
    int res = recur(a,n,k);
    cout << res;
}