#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<set<int>> numbers(n+1);
    vector<int> count(n+1,0);
    vector<set<int>> groups;
    for(int i = 1; i <= n;i++){
        int num;
        cin >> num;
        set<int> cur = {num};
        numbers[i] = cur;
        groups.push_back(cur);
    }


    map<int,int> starter; // end : start

    for(int i = 0; i < n-1; i++){
        int start;
        int end;
        cin >> start >> end;
        count[end] += 1;
        starter[end] = start;
    }

    queue<int> newone;
    for(int i = 1; i <= n; i++){
        if(count[i] == 0){
            newone.push(i);
        }
    }

    vector<int> answer(n+1, 0);

    while(!newone.empty()){
        int item = newone.front();
        newone.pop();
        count[starter[item]] -= 1;
        groups[starter[item]].insert(item);
        if(count[starter[item]] == 0){
            newone.push(starter[item]);
        }

        answer += 
    }





}