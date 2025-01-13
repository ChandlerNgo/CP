#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    deque<int> numbers;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    int answer = 0;

    while(!numbers.empty()){
        if(numbers.front() == numbers.back()){
            numbers.pop_front();
            if(!numbers.empty()){
                numbers.pop_back();
            }
            continue;
        }else{
            if(numbers.front() < numbers.back()){
                int num1 = numbers.front();
                numbers.pop_front();
                int num2 = numbers.front();
                numbers.pop_front();
                num1 += num2;
                numbers.push_front(num1);
            }else{
                int num1 = numbers.back();
                numbers.pop_back();
                int num2 = numbers.back();
                numbers.pop_back();
                num1 += num2;
                numbers.push_back(num1);
            }
            answer += 1;
        }
    }

    cout << answer << endl;
}