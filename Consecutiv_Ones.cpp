#include <iostream>
using namespace std;
string s;
void pem(int n,int one,int countzero,int len,bool p){
    if(!p&&len>=one){
        int count = 0;
        for(auto x : s){
            if(x=='1'){
                count++;
            }else{
                count = 0;
            }
            if(count==one){
                p=true;
                break;
            }
        }
        
    }
    if(len==n ){
        //cout<<s<<"\n";
        if(p){
            cout<<s<<"\n";
        }
        return ;
    }
    
    if(countzero>n-one){
        return ;
        
    }
    if(countzero<=n-one){
        s = s+ '0';
        pem(n,one,countzero+1,len+1,p);
        s.pop_back();
        
    }
    s = s+ '1';
    pem(n,one,countzero,len+1,p);
    s.pop_back();

}
int main(){
    int n,one;
    cin >> n >>one;
    pem(n,one,0,0,false);
}