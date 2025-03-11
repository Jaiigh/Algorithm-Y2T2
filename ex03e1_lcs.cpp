#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    string s1,s2;
    s1 = 'a';
    s2= 'b';
    string t ;
    cin >> t;
    s1 = s1 +t;
    cin >> t;
    s2 = s2 +t;
    vector<vector<int>> table(s1.size()+1,vector<int>(s2.size()+1));
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
                if(s1[i]==s2[j]){
                    table[i][j] = table[i-1][j-1]+1;
                }else{
                    table[i][j] = max(table[i-1][j],table[i][j-1]);
                }
        }
    }
    cout << table[s1.size()][s2.size()]-1;
}