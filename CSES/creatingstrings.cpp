#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Letters{
    string letters;
    string current;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<string> strings;
    
    queue<Letters> q;

    for(int i = 0; i < s.size(); i++){
        string cur = s;
        string m(1,s[i]);
        cur.erase(i,1);
        q.push({cur, m});
    }

    while(!q.empty()){
        Letters c = q.front();
        q.pop();
        if(c.current.size() == s.size()){
            strings.insert(c.current);
        }else{
            for(int i = 0; i < c.letters.size(); i++){
                string cur = c.letters;
                string m(1,cur[i]);
                cur.erase(i,1);
                q.push({cur, c.current + m});
            }
        }
    }

    cout << strings.size() << endl;
    for(auto str : strings){
        cout << str << endl;
    }
}