#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n,m,t;
    vector<int> unsort ;
    cin >> n>>m;
    
    for(int i=0;i<n;i++){
        cin>>t;
        unsort.push_back(t);
    }
    while(m--){
        int count =0;
        cin>>t;
        int i=0;
        while(unsort[i]!=t){
            if(unsort[i]>t){
                count++;
            }
            i++;
        }
        cout << count<<"\n";
    }
    
}
