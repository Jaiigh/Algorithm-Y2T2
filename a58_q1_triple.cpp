#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,q,tmp,tar;
    cin >> n >>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        
    }
    int sum ,l,r ;
    while(q--){
        cin>>tar;
        sum = 0;
        bool found = false;
        for(int i=0;i<n-2;i++){
            l = i+1;
            r = n-1;
            sum=a[i];
            sum+= a[l] ;
            sum+= a[r] ;
            while(l!=r){
                //cout << "i=" <<i<< "l=" <<l<< "i=" <<r<<"\n";
                if(sum==tar){
                    found = true;
                    break;
                }else if(sum<tar){
                    sum-= a[l];
                    l++;
                    sum+=a[l];
                }else{
                    sum-=a[r];
                    r--;
                    sum+=a[r];
                }
            }
            if(found) break;
        }
        if(found){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        
    }
}