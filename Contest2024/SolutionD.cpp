#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int find_index_not_in_set(set<int> a, int i){
    if(a.size() == i){
        return 0;
    }

    // binary search, max i not in set
    while(i > 0){
        if(a.find(i) != a.end()){
            i -= 1;
        }else{
            return i;
        }
    }
    return i;
}

int dp(vector<int>& a, vector<int>& b, set<int> problems, int score, int index){
    if(index == 0){
        return score;
    }
    // skip
    problems.insert(index);
    int skipScore = dp(a, b, problems, score, find_index_not_in_set(problems, b[index-1]));

    // do
    int doScore = dp(a, b, problems, score+a[index-1], find_index_not_in_set(problems, index));
    cout << "i: " << index << endl;
    return max(doScore, skipScore);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> a;
        vector<int> b;
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            a.push_back(num);
        }
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            b.push_back(num);
        }


        set<int> problems;
        problems.insert(1);
        cout << max(dp(a,b,problems,0,b[0]),a[0]) << endl;
    }
}