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
   int n;
   cin >>n;
   vector<int> c(n+1),m(n+1);
   for(int i=1;i<=n;i++){
        cin >> c[i];
   }
   m[1]=c[1];
    m[2] = max(c[1],c[2]);
   for(int i=3;i<=n;i++){
        m[i] = ma(m[i-2],m[i-1],m[i-3]+c[i]);
   }
   cout << m[n];
}