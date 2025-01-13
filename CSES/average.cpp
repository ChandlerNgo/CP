#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    float sum = 0;
    vector<float> numbers;
    for(int i = 0; i < n; i++){
        float num;
        cin >> num;
        sum += num;
        numbers.push_back(num);
    }
    std::sort(numbers.begin(),numbers.end());
    cout << sum/n << endl;
    if(n % 2 == 0){
        cout << (numbers[n/2]+numbers[(n/2)-1])/2 << endl;
    }else{
        cout << (n/2)-1 << endl;
    }

    return 0;
}