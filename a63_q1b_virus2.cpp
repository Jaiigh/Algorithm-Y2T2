#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool check(int n, vector<int> a){
    if(n==2){
        return true;
    }else{
        int m = n/2;
        int sum1=0,sum2=0;
        vector<int> f(m),s(m);
        for(int i=0;i<m;i++){
            f[i] = a[i];
            sum1+=a[i];
            s[i] = a[m+i];
            sum2+=a[m+i];
        }
        if(abs(sum1-sum2)>1){
            return false;
        }
        bool f1 = check(m,f);
        bool s1 = check(m,s);

        return s1 && f1;

    }

    
}
int main(){
    int m,n;
    cin >> m >>n;
    int size = pow(2,n);
    vector<int> a(size);
    while(m--){
        for(int i=0;i<size;i++){
            cin >> a[i];
        }
        if(check(size,a)){
            cout <<"yes"<<"\n";
        }else{
            cout <<"no"<<"\n";
        }
    }
}