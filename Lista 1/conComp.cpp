#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<vector<int>> g;
vector<bool> vis;

void bfs(int s, vector<char>& comp){
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int c = q.front();
        q.pop();
        comp.push_back(c + 'a');

        for(int i : g[c]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int main() { _
    int n;
    int c = 1;
    cin >> n;
    while(n--){
        int v,e;
        cin >> v >> e;

        g.clear();
        vis.clear();
        g.resize(v,vector<int>{});
        vis.resize(v, false);
        vector<vector<char>> comps;
        
        for(int i = 0; i < e; i++){
            char u,v;
            cin >> u >> v;
            g[u-'a'].push_back(v-'a');
            g[v-'a'].push_back(u-'a');
        }

        for(int i = 0; i < v; i++){
            if(g[i].empty() && !vis[i]){
                char ch = i+'a';
                vector<char> cc = {ch};
                comps.push_back(cc);
            }else if(!vis[i]){
                vector<char> cc;
                bfs(i, cc);
                sort(cc.begin(), cc.end());
                comps.push_back(cc);
            }
        }

        cout << "Case #" << c << ":" << endl;
        for(auto& comp : comps){
            for(char c : comp){
                cout << c << ",";
            }
            cout << endl;
        }
        cout << comps.size() << " connected components" << endl << endl;
        c++;
    }

}