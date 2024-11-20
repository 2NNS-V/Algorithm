#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    vector<int> stack;
    
    int i, j, k = 0;
    while (i < moves.size()) {
        bool check = false;
        
        i = moves[k++] - 1;
        for (j = 0; j < size; j++) {
            if (board[j][i] != 0) {
                check = true;
                cout << j << " " << i << endl;
                break;
            }
        }
        
        if (check) {
            stack.push_back(board[j][i]);
            board[j][i] = 0;
        
            if (stack.size() > 1) {
                for (int q = 1; q < stack.size(); q++) {
                    if (stack[q] == stack[q-1] ) {
                        stack.pop_back();
                        answer++;
                        stack.pop_back();
                        answer++;
                    }

                }
            }
        }
            
    } 
    
    return answer;
}