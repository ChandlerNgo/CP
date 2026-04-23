#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    int p;
    cin >> w >> p;
    vector<int> partitions;
    for(int i = 0; i < p; i++){
        int num;
        cin >> num;
        partitions.push_back(num);
    }
    set<int> sizes;
    for(int i = 0; i < p; i++){
        sizes.insert(partitions[i]);
        sizes.insert(w-partitions[i]);
        for(int j = i+1; j < p; j++){
            sizes.insert(partitions[j]-partitions[i]);
        }
    }
    vector<int> numbers;
    for(auto i = sizes.begin(); i != sizes.end(); i++){
        numbers.push_back(*i);
    }
    sort(numbers.begin(), numbers.end());
    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << " ";
    }
    cout << w << endl;
}