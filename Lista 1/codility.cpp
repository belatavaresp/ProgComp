#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int q1(vector<int> &A){
    vector<bool> visited(A.size(), false);
    int c = A[0];
    if(c== -1){
        return 1;
    }
    int cnt = 1;
    while(!visited[c]){
        visited[c] = true;
        if(A[c] >= 0){
            c = A[c];
        }else{
            cnt++;
            break;
        }
        cnt++;
    }
    return cnt;
}

int q2(int k, vector<int>& A){
    int n = A.size();
    int count = 0, l = 0;
    multiset<int> w;

    for(int r = 0; r < n; ++r){
        w.insert(A[r]);

        while(*w.rbegin() - *w.begin() > k){
            w.erase(w.find(A[l]));
            l++;
        }

        count += r-l+1;
        if(count > 1000000000) return 1000000000;
    }
    return count;
}
struct tree{
    int x;
    tree * l;
    tree * r;

    tree(int x_, tree* l_ = nullptr, tree* r_ = nullptr) 
        : x(x_), l(l_), r(r_) {}
}typedef tree;

void rec(tree * T, bool left, int len, int& maxP){
    if(T == nullptr){
        return;
    }

    maxP = max(maxP, len);

    if(left){
        rec(T->r, false, len+1, maxP);
        rec(T->l, true, len, maxP);
    }else{
        rec(T->l, true, len+1, maxP);
        rec(T->r, false, len, maxP);
    }
}

int solution(tree * T){
    if(T == nullptr){
        return 0;
    }
    int maxP = 0;
    rec(T->r, false, 0, maxP);
    rec(T->l, true, 0, maxP);

    return maxP; 
}

int main(){
    tree* root = new tree(5, 
        new tree(3, 
            new tree(20, 
                new tree(6)
            )
        ),
        new tree(10, 
            new tree(1),
            new tree(15, 
                new tree(30, 
                    nullptr, 
                    new tree(9)
                ),
                new tree(8)
            )
        )
    );

    cout << solution(root) << endl;
}