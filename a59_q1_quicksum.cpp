#include <iostream>
using namespace std;
int main(){
    int n,m,k;
    cin >> n>>m>>k;
    int a[n][m],dp[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
    }
    }
    dp[0][0] = a[0][0];
    for(int j=1;j<m;j++){
        dp[0][j] = dp[0][j-1] + a[0][j];
    }
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + a[i][0];
        for(int j=1;j<m;j++){
            dp[i][j] = dp[i-1][j] +dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }
    int r1,r2,c1,c2;
    int d,b,c;
    
    while(k--){
        cin>> r1>>c1>>r2>>c2;
        //cout<<"check"<<dp[r2][c2]<<"\n";
        
        if(r1==0||c1==0){
            if(r1==0&&c1!=0){
                 b = 0;
                c = dp[r2][c1-1];
                d = 0;
            }else  if(r1!=0&&c1==0){
                 b = dp[r1-1][c2];
                c = 0;
                d = 0;
            }else{
                b=0;
                d = 0;
                c=0;
            }
           
        }else{
            b = dp[r1-1][c2];
            c = dp[r2][c1-1];
            d = dp[r1-1][c1-1];
        }
       
        cout<<dp[r2][c2] - b  -c + d <<"\n";
        // cout<< "ans"<<dp[r2][c2] - b  -c + d <<"\n";
    }
}