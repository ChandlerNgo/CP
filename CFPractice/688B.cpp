#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >> n;

    cout << n + string(n.rbegin(),n.rend()) << "\n";
}