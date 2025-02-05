#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n,m,k,w,temp;
    cin >> n >> m >> k >>w;
    vector<int> p,t;
    map<int,int> h;
    for(int i=0;i<m;i++){   
        cin >> temp;
        p.push_back(temp);//position
    }
    int sum=0;
    for(int i=0;i<m;i++){   
        cin >> temp;
        sum+=temp;
        h[p[i]]+=temp;//health
    }
    for(int i=0;i<k;i++){   
        cin >> temp;
        t.push_back(temp);
    }
    sort(t.begin(),t.end());
    auto it = h.begin();
    int i = 0;
    while (true)
    {
        if(it==h.end()||i==k){
            break;
        }
        if(it->second==0){
            it++;
            continue;
        }
        if(it->first>=t[i]-w && it->first<=t[i]+w){
            if(it->second>0){
                sum--;
                it->second--;
                i++;
            }else{
                it++;
            }
            
            continue;
        }else if(it->first<t[i]-w){
            it++;
            continue;
        }else if(it->first>t[i]+w){
            i++;
            continue;
        }
        
    }
    cout << sum;

}