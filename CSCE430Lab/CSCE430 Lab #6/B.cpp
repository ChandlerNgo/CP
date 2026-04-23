#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    multiset<int> currentArrows;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        auto iter = currentArrows.find(num);
        if(iter == currentArrows.end()){
            currentArrows.insert(num-1);
        }else{
            currentArrows.erase(iter);
            currentArrows.insert(num-1);
        }
    }
    cout << currentArrows.size() << endl;
}