#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int m,n;
    while(cin >> m >> n, m && n){
        m = m*100;
        n = n*100;
        int l;
        cin >> l;
        int k; 
        cin >> k;
        multiset<int> tbh;
        multiset<int> tbv;
        for(int i = 0; i < k; i++){
            int v;
            cin >> v;
            tbh.insert(v*100);
            tbv.insert(v*100);
        }
        if((m%l!=0) && (n%l!=0)){
            cout << "impossível" << endl;
            continue;
        }
        int mtb = INF;
        if(m%l==0){
            int h = 0;
            for(int i = 0; i < m/l; i++){
                if(tbh.find(n)!= tbh.end()){
                    tbh.erase(tbh.find(n));
                    h++;
                    continue;
                }
                bool f = false;
                for(auto it = tbh.begin(); it!=tbh.end();){
                    if(*it > n){
                        break;
                    }
                    auto p = tbh.find(n-*it);
                    if(p!=tbh.end()&&p!=it){
                        f = true;
                        tbh.erase(it++);
                        tbh.erase(p);
                        h+=2;
                        break;
                    }else{
                        it++;
                    }
                }
                if(f==false){
                    h=INF;
                    break;
                }
            }
            mtb = min(mtb, h);
        }

        if(n%l==0){
            int v = 0;
            for(int i = 0; i < n/l; i++){
                if(tbv.find(m)!= tbv.end()){
                    tbv.erase(tbv.find(m));
                    v++;
                    continue;
                }
                bool f = false;
                for(auto it = tbv.begin(); it!=tbv.end();){
                    if(*it > m){
                        break;
                    }
                    auto p = tbv.find(m-*it);
                    if(p!=tbv.end() && p!=it){
                        f = true;
                        tbv.erase(it++);
                        tbv.erase(p);
                        v+=2;
                        break;
                    }else{
                        it++;
                    }
                }

                if(f == false){
                    v=INF;
                    break;
                }
            }
            mtb = min(mtb, v);
        }

        if(mtb == INF){
            cout << "impossivel" << endl;
        }else{
            cout << mtb << endl;
        }

    }
	exit(0);
}