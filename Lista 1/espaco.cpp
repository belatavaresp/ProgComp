#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<int> p,r;
vector<tuple<int, int, int>> eg;
vector<tuple<int, int, int>> es;

int find(int x){
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}

void uni(int x, int y){
    int rx = find(x);
    int ry = find(y);
    if (rx != ry){
        if(r[rx] < r[ry]){
            p[rx] = ry;
        }else if(r[rx] > r[ry]){
            p[ry] = rx;
        }else{
            p[ry] = rx;
            r[rx]++;
        }
    }
}

int main() { _
    int n;
    cin >> n;
    int cmin = 0;
    int cmax = 0;

    p.resize(n);
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    r.resize(n,1);
    for(int i = 0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        eg.push_back({-c, a, b}); // decres
        es.push_back({c, a, b}); // cres
    }

    sort(eg.begin(), eg.end());
    int cnt = 0;
    for(auto [w,u,v]: eg){
        if(find(u) != find(v)){
            uni(u, v);
            cmax -= w;
            if(++cnt == n-1){
                break;
            }
        }
    }

    p.resize(n);
    r.assign(n, 1);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    sort(es.begin(), es.end());
    cnt = 0;
    for(auto [w,u,v]: es){
        if(find(u) != find(v)){
            uni(u, v);
            cmin += w;
            if(++cnt == n-1){
                break;
            }
        }
    }
    cout << cmax << endl << cmin << endl;

	exit(0);
}