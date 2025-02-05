#include <iostream>
#include <map>
using namespace std;
int main(){
    int n,f,s,max=0,i;
    cin >>n;
    map<int,int> m;
    for( i=0;i<n;i++){
        cin >> f>>s;
        if(f>max){
            max = f;
        }
        if(s>max){
            max = s;
        }
        m[f]+=1;
        m[s]-=1;
    }
    int count = 0;
    auto it = m.begin();
    if(m.size()==1){
        cout <<it->first <<" "<<it->first;
        return 0 ;
    }
    for( it = m.begin();it!=m.end();it++){
        count +=it->second;
        f = it->first;
        while(true){
            it++;
            count +=it->second;
            if(count==0&&m.count((it->first)+1)==0){ // check others condition m.count((it->first)+1)==0
                if(m.count((it->first)+1)==0){ //ถ้าด้านหลังมีแต่เปนค่าติดลบก็ต้องไปต่อ
                    s=it->first; 
                    break; // รู้ละตอนนี้โค้ดจะพิมถ้า input เปนเลขเดียวกัน มันจะหักล้างกัน จนหายไปเอง ละไม่พิมออกมา
                }
               
            }
        }
        cout<<f<<" "<<s<<" ";

    }
    

}