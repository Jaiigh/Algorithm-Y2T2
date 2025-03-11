#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ma(int a,int b,int c){
    int t = max(a,b);
    t = max(t,c);
    return t;
}
int re(int n,vector<int> &s,vector<int> &m,vector<bool> &hasV){
    if(hasV[n]==true){
        return m[n];
    }else{
        if(n==1){
            m[1] = s[1];
            hasV[1] = true;
        return s[1];
    }
    if(n==2){
        m[2] = s[2]+s[1];
        hasV[2] = true;
        return m[2];
    }
    if(n==3){
        m[3] = max(s[3]+s[2]+s[1],s[3]+s[1]);
        hasV[3] = true;
        return m[3];
        
    }
    m[n] = ma(re(n-1,s,m,hasV),re(n-2,s,m,hasV),re(n-3,s,m,hasV))+s[n];
    hasV[n] = true;
    return m[n];
    } 
    
}
int main(){
    int n,k;
    cin >> n;
    vector<int> s(n+1),m(n+1);
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    vector<bool> haveValue(n+1,false);
    cout << re(n,s,m,haveValue);
}