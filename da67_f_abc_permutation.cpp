#include <iostream>
#include <vector>
using namespace std;
void pem(int N,int i,int j,int k,vector<string> &ans,int len,string now){
    if(len==N){
        ans.push_back(now);
        return ;
    }
    if(i>0){
        pem(N,i-1,j,k,ans,len+1,now+'A');
    }
    if(j>0){
        pem(N,i,j-1,k,ans,len+1,now+'B');
    }
    if(k>0){
        pem(N,i,j,k-1,ans,len+1,now+'C');
    }
}
int main(){
    int N,i,j,k;
    cin >> N >> i >> j >>k;
    vector<string> ans;
    pem(N,i,j,k,ans,0,"");
    cout <<  ans.size()<<endl;
    for (auto s : ans) {
        cout <<s <<endl;
    }
}