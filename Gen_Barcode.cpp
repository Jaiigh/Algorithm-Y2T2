#include <iostream>
using namespace std;
string s;
void recur(int one,int zero,int n,int len){
    if(len==n){
        cout << s<<"\n";
        return ;
    }
    if(zero>0){
        s = s+"0";
        recur(one,zero-1,n,len+1);
        s.pop_back();
    }
    if(one>0){
        s = s+"1";
        recur(one-1,zero,n,len+1);
        s.pop_back();
    }
    
}
int main(){
    int one,n;
    
    cin >> one >> n;
    recur(one,n-one,n,0);
}