#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        stack<int> notes;
        for(int j = 0; j < n; j++){
            cin >> s;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '#'){
                    notes.push(i+1);
                    break;
                }
            }
        }
        while(!notes.empty()){
            cout << notes.top() << " ";
            notes.pop();
        }
        cout << endl;
    }  
}