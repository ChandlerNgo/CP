#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void printVals(vector<string> command, map<string,int> words){
    int curSum = 0;
    bool notFound = false;
    if(words.find(command[0]) != words.end()){
        curSum += words[command[0]];
    }else{
        notFound = true;
    }
    cout << command[0] << " ";
    for(int i = 1; i < command.size()-1; i += 2){
        string word = command[i+1];
        string sign = command[i];
        if(words.find(word) == words.end()){
            notFound = true;
        }else{
            if(sign == "+"){
                curSum += words[word];
            }else if(sign == "-"){
                curSum -= words[word];
            }
        }
        cout << sign << " " << word << " ";
    }


    if(notFound){
        cout << "= unknown" << endl;
    }else{
        bool found = false;
        string word = "unknown";
        for(auto iter : words){
            if(iter.second == curSum){
                found = true;
                word = iter.first;
                break;
            }
        }
        cout << "= " << word << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string command;

    map<string,int> words;
    while(cin >> command){
        if(command == "def"){
            string word;
            int val;
            cin >> word >> val;
            words[word] = val;
        }else if(command == "calc"){
            vector<string> currentCommand;
            string word;
            string sign;
            cin >> word >> sign;
            while(sign != "="){
                currentCommand.push_back(word);
                currentCommand.push_back(sign);
                cin >> word >> sign;
            }

            currentCommand.push_back(word);
            currentCommand.push_back(sign);

            printVals(currentCommand,words);

        }else if(command == "clear"){
            words.clear();
        }
    }
}

// def foo 3
// calc foo + bar =
// def bar 7
// def programming 10
// calc foo + bar =
// def is 4
// def fun 8
// calc programming - is + fun =
// def fun 1
// calc programming - is + fun =
// clear
