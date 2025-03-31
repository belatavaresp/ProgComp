#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    while(cin >> n){
        vector<int> h = {0,0,0}; // s, q, pq
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while(n--){
            int c, x;
            cin >> c >> x;
            if(c == 1){
                s.push(x);
                q.push(x);
                pq.push(x);
            }else{
                int sp = s.top();
                s.pop();
                int qp = q.front();
                q.pop();
                int pqp = pq.top();
                pq.pop();
                if (x != sp){
                    h[0] = 1;
                }
                if( x != qp){
                    h[1] = 1;
                }
                if( x != pqp){
                    h[2] = 1;
                }
            }
        }
        if ((h[0] == 0 && h[1] == 0 && h[2] == 0) || 
        (h[1] == 0 && h[2] == 0) || 
        (h[0] == 0 && h[1] == 0) || 
        (h[0] == 0 && h[2] == 0)
        ){
            cout << "not sure" << endl;
        }else if(h[0]==h[1]==h[2]==1){
            cout << "impossible" << endl;
        }else{
            if(h[0] == 0){
                cout << "stack" << endl;
            }else if(h[1] == 0){
                cout << "queue" << endl;
            }else if(h[2] == 0){
                cout << "priority queue" << endl;
            }else{
                cout << "deu ruim" << endl;
            }
        }
    }
	exit(0);
}
