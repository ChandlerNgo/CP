#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<int,int> numbers;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(numbers.find(num) == numbers.end()){
            numbers[num] = 1;
        }else{
            numbers[num] += 1;
        }

    }
    if(numbers.size() != 2){
        cout << "NO\n";
        return 0;
    }

    int first;
    int firstamt;
    int second;
    int secondamt;

    for(auto i = numbers.cbegin(); i != numbers.cend(); i++){
        if(i == numbers.cbegin()){
            first = i->first;
            firstamt = i->second;
        }else{
            second = i->first;
            secondamt = i->second;
        }
    }

    if(firstamt == secondamt){
        cout << "YES\n";
        cout << first << " " << second << "\n";
    }else{
        cout << "NO\n";
    }
}