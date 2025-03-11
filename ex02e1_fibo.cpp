#include<iostream>
using namespace std;
int main(){
    int f,f1=1,f2=1;
    int n;
    cin >>n;
    if(n==1||n==2){
        cout << 1;
        return 0;
    }
    n=n-2;
    while(n--){
        f = f1+f2;
        f1 = f2;
        f2 = f;
    }
    cout<<f;
}