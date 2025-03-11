#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout<<3;
        return 0;
    }
    if(n==2){
        cout <<7;
        return 0;
    }
    vector<int> dp(n+1);
    dp[1] =3;
    dp[2] =7;
    for(int i=3;i<=n;i++){
        dp[i] = (2*dp[i-1] + dp[i-2])%100000007;
    }
    cout <<dp[n];
}