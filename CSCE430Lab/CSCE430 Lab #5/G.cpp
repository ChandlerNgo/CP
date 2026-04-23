#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> left;
    vector<int> right;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        if(command == "get"){
            int index;
            cin >> index;
            if(index < left.size()){
                cout << left[index];
            }else{
                index -= left.size();
            }
        }else if(command == "push_back"){
            int val;
            cin >> val;
            if(left.size() > right.size()){
                right.push_back(val);
            }else{
                left.push_back(right[0]);
                right.pop_back()
            }
        }
    }
}