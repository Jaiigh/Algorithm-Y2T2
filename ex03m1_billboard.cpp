#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   int n;
   cin >>n;
   vector<int> c(n+1),m(n+1);
   for(int i=1;i<=n;i++){
        cin >> c[i];
   }
   m[1]=c[1];
   for(int i=2;i<=n;i++){
        m[i] = max(m[i-2]+c[i],m[i-1]);
   }
   cout << m[n];
}