#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers[i] = num;
    }

    ll maxArea = 0;
    vector<int> indexes;
    vector<int> values;
    for(int i = 0; i < n; i++){
        int start = i;
        while(!indexes.empty() && values[values.size()-1] > numbers[i]){
            int index = indexes[indexes.size()-1];
            indexes.pop_back();
            int value = values[values.size()-1];
            values.pop_back();
            maxArea = max(maxArea, (ll) value*(i-index));
            start = index;
        }
        indexes.push_back(start);
        values.push_back(numbers[i]);
    }

    for(int i = 0; i < indexes.size(); i++){
        int index = indexes[i];
        int value = values[i];
        maxArea = max(maxArea, (ll) (value * (numbers.size() - index)));
    }
    cout << maxArea << endl;

}