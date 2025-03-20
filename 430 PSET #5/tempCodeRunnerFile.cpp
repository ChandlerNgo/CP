#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void placeShips(stack<pair<vector<string>,set<ll>>>& states, vector<string>& board, set<ll>& ships){
        ll ship = *ships.begin();
        set<ll> newShips = ships;
        newShips.erase(ship);
        // cout << ship << endl;
        // left right ships
        for(ll row = 0; row < board.size(); row++){
            for(ll base = 0; base < board.size()-ship+1; base++){
                bool canMake = true;
                for(ll shipPart = 0; shipPart < ship; shipPart++){
                    // cout << "1 " << row << " " << shipPart << endl;
                    if(board[row][base+shipPart] == 'X'){
                        canMake = false;
                        break;
                    }
                }
                if(canMake){
                    vector<string> newBoard = board;
                    for(ll shipPart = 0; shipPart < ship; shipPart++){
                        newBoard[row][base+shipPart] = 'X';
                    }
                    states.push({newBoard,newShips});
                }
            }
        }

        //up down ships
        if(ship == 1){
            return;
        }

        for(ll column = 0; column < board[0].size(); column++){
            for(ll base = 0; base < board[0].size()-ship+1; base++){
                bool canMake = true;
                for(ll shipPart = 0; shipPart < ship; shipPart++){
                    // cout << "2 " << shipPart << " " << column << endl;
                    if(board[base+shipPart][column] == 'X'){
                        canMake = false;
                        break;
                    }
                }
                if(canMake){
                    vector<string> newBoard = board;
                    for(ll shipPart = 0; shipPart < ship; shipPart++){
                        newBoard[base+shipPart][column] = 'X';
                    }

                    states.push({newBoard,newShips});
                }
            }
        }
    
}

bool isValid(vector<string>& board){
    for(ll i = 0; i < board.size(); i++){
        for(ll j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'O'){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll k;
    cin >> n >> k;
    vector<string> board;
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        board.push_back(s);
    }

    set<ll> ships;

    ll shipArea = 0;

    for(ll i = 0; i < k; i++){
        ll ship;
        cin >> ship;
        ships.insert(ship);
        shipArea += ship;
    }

    ll positions = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 'X'){
                positions += 1;
            }
        }
    }

    if(positions < shipArea){
        cout << 0 << endl;
        return 0;
    }

    stack<pair<vector<string>,set<ll>>> states;
    states.push({board,ships});
    ll possibilities = 0;
    while(!states.empty()){
        vector<string> curBoard = states.top().first;
        set<ll> curShip = states.top().second;
        states.pop();

        if(curShip.empty()){
            if(isValid(curBoard)){
                possibilities += 1;
            }
            continue;
        }else{
            placeShips(states,curBoard,curShip);
            cout << states.size() << endl;
        }
    }
    cout << possibilities << endl;
}