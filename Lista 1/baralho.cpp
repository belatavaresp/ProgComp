#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
string carta = "A23456789DQJK";

int valor(char c){
    return carta.find(c);
}

bool w(multiset<char>& h){
    if(h.size()<4)return false;
    return (*h.begin() == *h.rbegin());
}

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n, k;
    cin >> n >> k;
    k--;
    vector<multiset<char>> m(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >>s;
        for(char c : s){
            m[i].insert(c);
        }
    }
    int cur = k;
    int jk = k;
    int lastjk = -1;
    int rnd = 0;

    while(true){
        for(int i = 0; i < n; i++){
            if(w(m[i]) && jk != i){
                cout << i+1 << endl;
                return 0;
            }
        }

        int next = (cur + 1) % n;
        if(cur == jk && rnd == lastjk + n+1){
            jk = next;
            lastjk = rnd;
            cur = next;
            rnd++;
            continue;
        }

        map<char,int> f;
        for(char c : m[cur]) f[c]++;

        int lf = 5;
        char ch = 'Z';
        for (auto& [c, fr] : f) {
            if (fr < lf || (fr == lf && valor(c) < valor(ch))) {
                lf = fr;
                ch = c;
            }
        }
        m[cur].erase(m[cur].find(ch));
        m[next].insert(ch);

        cur = next;
        rnd++;
    }

	exit(0);
}