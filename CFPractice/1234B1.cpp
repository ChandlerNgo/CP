#include <bits/stdc++.h>

using namespace std;

int main(){
    // this solution works for the hard version 2 
    
    // read in n (num of messages), k (how many messages on the screen)


    // messages come in
    // [1,2]
    // if 3 comes in and k is 2
    // [3,1]
    // everything gets scooted down one
    // if 1/3 keep coming in they dont change

    // use set and queue
    // add item to set and queue if not in set
    // if you need to add the item and queue is full
    // remove first from queue

    // return reversed queue + len queue

    int n;
    int k;

    cin >> n >> k;

    set<long long> currentElements;
    deque<long long> currentMessages;

    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        if(currentElements.find(num) == currentElements.end()){
            if(currentElements.size() == k){
                currentElements.erase(currentMessages.front());
                currentMessages.pop_front();
                currentMessages.push_back(num);
                currentElements.insert(num);
            }else{
                currentElements.insert(num);
                currentMessages.push_back(num);
            }
        }
    }

    cout << currentMessages.size() << "\n";
    while(!currentMessages.empty()){
        cout << currentMessages.back() << " ";
        currentMessages.pop_back();
    }
    cout << "\n";
}