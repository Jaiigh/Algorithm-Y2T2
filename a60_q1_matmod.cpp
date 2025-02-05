#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
vector<int> mul_Matric( vector<int> &m, vector<int> &n,int k){
    int a = ((m[0]%k)*(n[0]%k) +(m[1]%k)*(n[2]%k))%k;
    int b = ((m[0]%k)*(n[1]%k) +(m[1]%k)*(n[3]%k))%k;
    int c = ((m[2]%k)*(n[0]%k) +(m[3]%k)*(n[2]%k))%k;
    int d = ((m[2]%k)*(n[1]%k) +(m[3]%k)*(n[3]%k))%k;
    vector<int> tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    tmp.push_back(d);
    return tmp;
}
vector<int> rec(int n,int k,vector<int>v){
    if(n==1){
        return v;
    }
    if(n%2==0){
        vector<int> tmp = rec(n/2,k,v);
        return mul_Matric(tmp,tmp,k);
    }else{
        vector<int> tmp = rec(n/2,k,v);
        tmp = mul_Matric(tmp,tmp,k);
        return mul_Matric(tmp,v,k);
    }
}
int main(){
    int n,k,t;
    cin >>n>>k;
    vector<int> v(4),a;
    for(int i=0;i<4;i++){
        cin>>v[i];
    }
    a = rec(n,k,v);
    for(int i=0;i<4;i++){
        cout<<a[i]<<" ";
    }
}