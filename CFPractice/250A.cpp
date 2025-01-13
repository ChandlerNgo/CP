#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int folder_size = 0;
    int negatives = 0;
    vector<int> folders;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num < 0){
            negatives += 1;
        }

        if(negatives == 3){
            folders.push_back(folder_size);
            folder_size = 1;
            negatives = 1;
        }else{
            folder_size += 1;
        }
    }
    if(folder_size > 0){
        folders.push_back(folder_size);
    }
    cout << folders.size() << endl;
    for(int i = 0; i < folders.size(); i++){
        cout << folders[i] << " ";
    }
    cout << endl;
}