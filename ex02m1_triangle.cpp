
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,t;
    cin >>n>>t;
    vector<int> v,m(n,0);
    m[0]=t;
    for(int i=1;i<n;i++){
        vector<int> tmp(i+1) ;
        for(int j=0;j<=i;j++){
            if(j==0){
                cin>>t;
                tmp[j]= m[0] +t;
            }else if(j==i){
                cin>>t;
                tmp[j]= m[j-1] +t;
            }else{
                cin >> t;
                tmp[j] = max(m[j],m[j-1])+t;
            }
            
            
        }
        m = tmp;
    }
    int max = m[0];
    for(int i=1;i<m.size();i++){
        if(max<m[i]){
            max = m[i];
        }
    }
    cout <<max;
}

