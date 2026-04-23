    #include <iostream>

    using namespace std;

    int main(){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            string first;
            string second;
            char temp;
            cin >> first >> second;
            temp = first[0];
            first[0] = second[0];
            second[0] = temp;
            cout << first << " " << second << endl;
        }
        return 0;
    }