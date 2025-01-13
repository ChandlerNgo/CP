#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int A, int B, int C){
    if(A <= B && B <= C && C == B + (B-A)){
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A;
    int B;
    cin >> A >> B;
    int amount = 0;
    for(int C = -200; C < 200; C++){
        int found = 0;
        found = found || solve(A,B,C);
        found = found || solve(A,C,B);
        found = found || solve(B,A,C);
        found = found || solve(B,C,A);
        found = found || solve(C,B,A);
        found = found || solve(C,A,B);
        amount += found;
    }
    cout << amount << endl;
}