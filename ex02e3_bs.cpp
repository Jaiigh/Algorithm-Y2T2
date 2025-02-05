#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,q,tar,l,r,m;
    cin >>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    while(q--){
        cin >> tar;
        if(a[0]>tar){
            cout <<-1<<"\n";
            continue;
        } 
        l = 0;
        r = n-1;
        while(l<r){
            m = (l+r+1)/2;
            if(a[m]<=tar){
                l = m;
            }else{
                r = m-1;
            }
        }
        cout <<l<<"\n";
    }
     
    
}