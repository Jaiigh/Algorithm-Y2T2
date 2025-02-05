#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void reverse(vector<int> &a){
    int tmp;
    for(int i=0;i<a.size()/2;i++){
        tmp = a[i];
        a[i] = a[a.size()-1-i];
        a[a.size()-1-i] = tmp;
    }
}
bool is_divoc(vector<int> &a){
    if(a.size()==2){
        return (a[0]==0) && (a[1]==1);
    }
    int m = a.size()/2;
    vector<int> f(m),s(m);
    for(int i=0;i<m;i++){
        f[i] = a[i];
        s[i] = a[m+i];
    }
    bool b1 =is_divoc(f) && is_divoc(s);
    
    reverse(f);
    bool b2 =is_divoc(f) && is_divoc(s);
    return b1||b2;
}
int main(){
    int n,k,tmp;
    cin >> n >>k;
    for(int i=0;i<n;i++){
        vector<int> q;
        for(int j=0;j<int(pow(2,k));j++){
            cin>> tmp;
            q.push_back(tmp);
        }
        if(is_divoc(q)){
            cout<<"yes"<<"\n";
        }else{
            cout<<"no"<<"\n";
        }
    }
}