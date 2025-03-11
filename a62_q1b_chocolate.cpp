#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ma(int a,int b, int c){
    int t= max(a,b);
    t = max(t,c);
    return t;
}

int main(){
   int n , price;
   cin >> price >>n;
   vector<vector<int>> table(n+1,vector<int>(price+1,0));
   vector<int> v(n+1);
   for(int i=1;i<=n;i++){
    cin >>v[i];
   }
   for(int i=0;i<=n;i++){
     table[i][0] = 0;
   }
   for(int i=0;i<=price;i++){
     table[0][i] = 0;
     if(i>0 &&i%v[1]==0){
        table[1][i] = 1;
     }
   }
   sort(v.begin(),v.end());
   for(int i=2;i<=n;i++){
        //cout<<"inI\n";
        for(int j=1;j<=price;j++){
            //cout<<"InJ"<<"\n";
            
            if(v[i]>j){
                table[i][j] = table[i-1][j];
            }else if(v[i]==j){
                table[i][j] = table[i-1][j]+1;
            }else{                 
                for(int k=1;k<=i;k++){
                //     if(i==2&&j==4)  {
                //     cout <<table[i][j-v[k]] <<"\n";
                //  }
                 table[i][j] = (table[i][j]+(table[i][j-v[k]]%1000003))%1000003;     
                 
                }
            //table[i][j] = (table[i][j]+(table[i-1][j]%1000003))%1000003;
        }
   }
   }
    //   for(int i=0;i<=n;i++){
    //     //cout<<"inI\n";
    //     for(int j=0;j<=price;j++){
    //         cout<<table[i][j]<<" ";
    //     }
    //     cout<<"\n";
    //     }
   cout <<table[n][price];
}