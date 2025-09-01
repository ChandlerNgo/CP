#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            pq.push(num);
        }

        ll count = 0;

        while(!pq.empty()){
            int one = pq.top();
            pq.pop();
            pq.pop();

            count += one;
            if(!pq.empty()){
                pq.push(0);
            }
        }

        cout << count << "\n";
    }
}