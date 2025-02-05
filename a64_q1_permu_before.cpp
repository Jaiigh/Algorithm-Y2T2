#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int,vector<int>> e;
void pem(int n, vector<int> & ans, vector<bool> & use,int len){
    if(len<n){
        for(int i=0;i<n;i++){
            if(use[i]==false){   
                bool canrecur = true;    
                if(e.count(i)!=0){
                    for(auto x:e[i]){
                        bool have = false;
                        for(int j=0;j<len;j++){
                            if(ans[j]==x){ // have can continue  recur
                                have = true;                                
                            }
                        }
                        if(!have ){
                            canrecur = false;
                            break;
                        }
                    }
                }
                if(!canrecur){
                    continue;
                }
                use[i]=true;
                ans[len] = i;
                pem(n,ans,use,len+1);
                use[i] = false;
            }
        }
    }else{
        for (auto &x : ans) cout << x <<" ";
        cout << "\n";
        return ;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> ans(n);
    vector<bool> b(n);
    
    for(int i=0;i<m;i++){
        int f,s;
        cin >> f>>s;
        e[s].push_back(f);
    }
    pem(n,ans,b,0);
}