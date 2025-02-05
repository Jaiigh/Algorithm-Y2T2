#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,count=0;
    cin >>n;
    int a[n]; //use array of int instead vector<int> แล้วผ่านT ตอนแรกใช้ vector ได้83/100 ใช้ array ละ100
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                count++;
            }
        }

    }
    cout <<count;
    
}