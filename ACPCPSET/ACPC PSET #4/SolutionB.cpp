#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        priority_queue<int> maxHeap;
        vector<int> numbers;
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            maxHeap.push(num);
            numbers.push_back(num);
        }
        bool maxFound = false;
        int firstMax = maxHeap.top();
        maxHeap.pop();
        int secondMax = maxHeap.top();
        maxHeap.pop();
        for(int j = 0; j < n; j++){
            if(numbers[j] == firstMax){
                if(maxFound){
                    cout << 0 << " ";
                }else{
                    cout << numbers[j] - secondMax << " ";
                    maxFound = true;
                }
            }else{
                cout << numbers[j] - firstMax << " ";
            }
        }
        cout << endl;
    }
}