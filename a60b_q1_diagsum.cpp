#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
    }
    }
    int max = INT_MIN;
    
    int sum =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum =0;
            for(int k=0;i+k<n && j+k<n;k++){
            sum += a[i+k][j+k];
                if(sum>max){
                    max = sum;
                }
    }
    }
    }
    cout << max;
}