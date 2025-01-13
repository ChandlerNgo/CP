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
        int k;
        cin >> n >> k;
        map<int,int> freq;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(freq.find(num) == freq.end()){
                freq[num] = 1;
            }else{
                freq[num] += 1;
            }
        }

        // sort numbers

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> numbers;
        for(auto i = freq.begin(); i != freq.end(); i++){
            numbers.push({i->first,i->second});
        }

        // slide window, size k
        deque<pair<int,int>> window;
        int maxCards = 0;
        int currentSum = 0;
        while(!numbers.empty()){
            if(window.empty()){
                window.push_back({numbers.top().first,numbers.top().second});
                currentSum += numbers.top().second;
                numbers.pop();
                maxCards = max(maxCards,currentSum);
                continue;
            }

            if(window.size() == k){
                if(window.back().first+1 == numbers.top().first){
                    maxCards = max(maxCards, currentSum);
                    window.push_back({numbers.top().first,numbers.top().second});
                    currentSum += numbers.top().second;
                    currentSum -= window.front().second;
                    window.pop_front();
                }else{
                    // clear queue, update max
                    maxCards = max(maxCards, currentSum);
                    currentSum = 0;
                    window.clear();
                    continue;
                }
            }else{
                if(window.back().first+1 == numbers.top().first){
                    window.push_back({numbers.top().first,numbers.top().second});
                    currentSum += numbers.top().second;
                }else{
                    // clear queue, update max
                    maxCards = max(maxCards, currentSum);
                    currentSum = 0;
                    window.clear();
                    continue;
                }
            }
            numbers.pop();
        }
        maxCards = max(maxCards,currentSum);
        cout << maxCards << endl;
    }
}