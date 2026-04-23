#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n){
        vector<int> types;
        vector<int> values;
        for(int i = 0; i < n; i++){
            int type;
            int val;
            cin >> type >> val;
            types.push_back(type);
            values.push_back(val);
        }
        bool isStack = true;
        bool isQueue = true;
        bool isPQueue = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            if(types[i] == 1){
                s.push(values[i]);
                q.push(values[i]);
                pq.push(values[i]);
            }else{
                if(s.empty() || s.top() != values[i]){
                    isStack = false;
                }
                if(q.empty() || q.front() != values[i]){
                    isQueue = false;
                }
                if(pq.empty() || pq.top() != values[i]){
                    isPQueue = false;
                }
                if(!s.empty()){
                    s.pop();
                }
                if(!q.empty()){
                    q.pop();
                }
                if(!pq.empty()){
                    pq.pop();
                }
            }
        }

        if(isStack + isQueue + isPQueue > 1){
            cout << "not sure\n";
        }else if(isStack + isQueue + isPQueue == 0){
            cout << "impossible\n";
        }else if(isStack){
            cout << "stack\n";
        }else if(isQueue){
            cout << "queue\n";
        }else{
            cout << "priority queue\n";
        }
    }
}