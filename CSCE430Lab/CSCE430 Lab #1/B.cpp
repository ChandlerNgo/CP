#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    int begin = numbers[0];
    int end = numbers[0];
    for(int i = 1; i < n; i++){
        if(end+1 == numbers[i]){
            end = numbers[i];
        }else{
            if(begin == end){
                cout << begin << " ";
            }else if(begin+1 == end){
                cout << begin << " " << end << " ";
            }else{
                cout << begin << "-" << end << " ";
            }
            begin = numbers[i];
            end = numbers[i];
        }
    }
    if(begin == end){
        cout << begin << " ";
    }else if(begin+1 == end){
        cout << begin << " " << end << " ";
    }else{
        cout << begin << "-" << end << " ";
    }
    cout << endl;
}
