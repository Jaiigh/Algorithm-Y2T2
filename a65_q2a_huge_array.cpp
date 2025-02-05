#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);
    int n,q,t1,t2;
    cin >> n >> q;
    int count=0;
    map<int,int> m1,m2;
    
    vector<int> v;
    for(int i=0;i<n;i++){
        cin >> t1 >> t2;
        if(m1.count(t1)>0){
            m1[t1] += t2;
        }else{
            m1[t1] = t2;
        v.push_back(t1);
        }
        
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        count+= m1[v[i]];
        m2[count] = v[i];
        
    }
   
    while(q--){
        cin >> t1;
        auto it = m2.lower_bound(t1);
        if(it==m2.end()){
            it--;
            cout<<it->second <<"\n";
        }else{
            cout<<it->second <<"\n";
        }
        
        
    }
}