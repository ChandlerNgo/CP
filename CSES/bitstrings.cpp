#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    long long answer = 1;
    for(int i = 1; i <= n; i++){
        answer *= 2;
        answer = answer % 1000000007;
    }
    cout << answer;
    
    return 0;
}