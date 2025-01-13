#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }

    vector<int> first;
    vector<int> second;
    long long first_sum = 0;
    if(sum % 2 == 0){
        cout << "YES" << endl;
        while(n != 0){
            long long total_sum = (sum / 2) - first_sum;
            if(total_sum >= n){
                first.push_back(n);
                first_sum += n;
            }else{
                second.push_back(n);
            }
            n -= 1;
        }

        cout << first.size() << endl;
        for(int i = 0; i < first.size(); i++){
            cout << first[i] << " ";
        }
        cout << endl;
        cout << second.size() << endl;
        for(int i = 0; i < second.size(); i++){
            cout << second[i] << " ";
        }
        cout << endl;

    }else{
        cout << "NO" << endl;
    }


    return 0;
}