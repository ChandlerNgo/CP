#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> items;
    ll discount = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        items.push(num);
    }   

    while(items.size() > 2){
        items.pop();
        items.pop();
        discount += items.top();
        items.pop();
    }
    cout << discount << endl;
}