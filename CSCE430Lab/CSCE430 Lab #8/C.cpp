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
        vector<int> numbers(13,0);
        for(int i = 0; i <= 12; i++){
            cin >> numbers[i];
        }

        int islands = 0;

        stack<int> stack;
        for(int i = 1; i <= 12; i++){
            set<int> elements;
            while(!stack.empty() && numbers[i] < stack.top()){
                if(elements.find(stack.top()) == elements.end()){
                    islands += 1;
                    elements.insert(stack.top());
                }
                stack.pop();
            }
            stack.push(numbers[i]);
        }
        cout << numbers[0] << " " << islands << "\n";
    }
    cout << flush;
}