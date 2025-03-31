#include <iostream>
#include <vector>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void pos(string& pre, string& infx, string& res){
    if(pre.empty()) return;
    char r = pre[0];
    int pr = infx.find(r);
    string ie = infx.substr(0, pr);
    string id = infx.substr(pr+1);
    string pe = pre.substr(1, ie.length());
    string pd = pre.substr(1+ie.length());

    pos(pe, ie, res);
    pos(pd, id, res);
    res+=r;
}

int main() { _
    int c;
    cin >> c;
    while(c--){
        int n;
        string p, i, r = "";
        cin >> n >> p >> i ;
        pos(p, i, r);
        cout << r << endl;
    }
	exit(0);
}