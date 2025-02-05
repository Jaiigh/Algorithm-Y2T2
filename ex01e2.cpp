#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int getsum(vector<int>s,int a,int b){
    return s[b]-s[a-1];
}
int mss(vector<int> a,int start,int stop,vector<int> s){
    
    if(start==stop){
        return a[start];
    }
    int m = (start+stop)/2;
    int r1 = mss(a,start,m,s);
    int r2 = mss(a,m+1,stop,s);
    int msl = getsum(s,m,m);
    for(int i=start;i<m;i++){
        msl = max(msl,getsum(s,i,m));
    }
    int msr = getsum(s,m+1,m+1);
    for(int i=m+2;i<stop+1;i++){
        msr = max(msr,getsum(s,m+1,i));
    }
    int r3 = msl+msr;
    if(msl>msr){
        return max(msl,r3);
    }else{
        return max(msr,r3);
    }
    
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n),s(n+1);
    
    s[0] = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s[i+1]=s[i]+a[i];
    }
    cout << mss(a,0,n-1,s);

}