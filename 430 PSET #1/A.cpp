#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int s; // index
    int m; // magic number
    cin >> n >> s >> m;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    int cycles = 0;
    set<int> visited;
    s -= 1;
    while(true){
        if(numbers[s] == m){
            cout << "magic" << endl;
            break;
        }
        if(visited.find(s) != visited.end()){
            cout << "cycle" << endl;
            break;
        }else if((s+numbers[s]) < 0){
            cout << "left" << endl;
            cycles += 1;
            break;
        }else if((s+numbers[s]) >= n){
            cout << "right" << endl;
            cycles += 1;
            break;
        }

        cycles += 1;
        visited.insert(s);
        s += numbers[s];
    }
    cout << cycles << endl;
}