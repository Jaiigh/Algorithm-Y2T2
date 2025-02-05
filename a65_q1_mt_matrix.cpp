#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,q;
    int u,v,w,p;
    long long  r,c;
    cin >> n>>q;
    cin >> u>>v>> w>>p;
    vector<int> tmp;
    vector<vector<int>> ans;
    tmp.push_back(u);
    tmp.push_back(v);
    tmp.push_back(u);
    tmp.push_back(w);
    ans.push_back(tmp);
    tmp.clear();
    tmp.push_back(w);
    tmp.push_back(p);
    tmp.push_back(v);
    tmp.push_back(p);
    ans.push_back(tmp);
    tmp.clear();
    tmp.push_back(-1*u);
    tmp.push_back(-1*v);
    tmp.push_back(-1*u);
    tmp.push_back(-1*w);
    ans.push_back(tmp);
    tmp.clear();
    tmp.push_back(-1*w);
    tmp.push_back(-1*p);
    tmp.push_back(-1*v);
    tmp.push_back(-1*p);
    ans.push_back(tmp);
    
     while(q--){
         cin >> r >>c;
         r = (r-1)%4;
         c = (c-1)%4;
        cout<<ans[r][c]<<"a\n";
     }
}