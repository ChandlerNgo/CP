#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
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

    int answer = 0;
    vector<int> a(n,1);
    vector<int> b(n,1);
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(numbers[j] > numbers[i]){
                a[i] = max(a[i], a[j] + 1);
            }
            
            if(numbers[j] < numbers[i]){
                b[i] = max(b[i], b[j] + 1);
            }
        }
        answer = max(answer, a[i] + b[i] - 1);
    }

    cout << answer << endl;
}