#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int level;
    cin >> level;
    set<int> levels;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        levels.insert(num);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        levels.insert(num);
    }
    if(levels.size() == level){
        cout << "I become the guy." << endl;
    }else{
        cout << "Oh, my keyboard!" << endl;
    }
}