#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

map<char, string> mib = {{'1', "100000"},{'2', "101000"}, {'3', "110000"}, {'4', "110100"}, {'5', "100100"}, {'6', "111000"}, {'7', "111100"}, {'8', "101100"}, {'9', "011000"}, {'0', "011100"}};
map<string, int> mbi = {{"100000", 1}, {"101000", 2}, {"110000", 3}, {"110100", 4}, {"100100", 5}, {"111000", 6}, {"111100", 7}, {"101100", 8}, {"011000", 9}, {"011100", 0}};

void print_braile(vector<string> br){
    int st = 0;
    int c = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < br.size(); j++){
            for(int k = st; k <= c; k++){
                if(br[j][k] == '0') cout << ".";
                if(br[j][k] == '1') cout << "*";
            }
            if (j != br.size() - 1) cout << " ";
        }
        cout << endl;
        c+=2;
        st+=2;
    }
}

vector<string> read_braile(int n){
    vector<string> br(n,"");
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                char in;
                cin >> in;
                if(in == '*') br[j]+='1';
                if(in == '.') br[j]+='0';
            }
        }
    }
    return br;
}

int main() { _
    int n = 3;
    while(cin>>n){
        if(n==0){
            exit(0);
        }

        char c;
        cin>>c;
        if(c=='S'){
            vector<string>br;
            for(int i = 0; i < n; i++){
                char ch;
                cin >> ch;
                br.push_back(mib[ch]);
            }
            print_braile(br);
        }else if(c == 'B'){
            vector<string>br = read_braile(n);
            for(int i = 0; i < br.size();i++){
                cout << mbi[br[i]];
            }
            cout << endl;
        }
    }

	exit(0);
}