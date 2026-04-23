#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    vector<int> nums;
    while(getline(cin, line)){
        int M; int P; int L; int E; int R; int S; int N;
        stringstream ss(line);
        ss >> M >> P >> L >> E >> R >> S >> N;
        for(int i = 0; i < N; i++){
            int newM = 0;
            int newP = 0;
            int newL = 0;
            newL += (M*E);
            newP = (L/R);
            newM = (P/S);
            L = newL;
            P = newP;
            M = newM;
        }
        nums.push_back(M);
    }
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
}