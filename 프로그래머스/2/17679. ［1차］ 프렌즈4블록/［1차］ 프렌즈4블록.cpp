#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 같은 블록이 2*2 로 모여 있으면 삭제 -> 밑으로 떨어짐
// 블록 몇 개가 지워지는지 확인


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (1) {
        vector<vector<int>> mark(m, vector<int> (n, 0));
        bool any = false;
        
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (board[i + 1][j] == c && board[i+1][j+1] == c && board[i][j+1] == c) {
                    mark[i][j] = mark[i+1][j] = 1;
                    mark[i+1][j+1] = mark[i][j+1] = 1;
                    any = true;
                }
            }
        }
        if (!any) break;
        
        // 없애주기
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mark[i][j]) {
                    board[i][j] = '.';
                    answer++;
                }
            }
        }
        
        
        // 내려와
        for (int j = 0; j < n; j++) {
            int write = m - 1;
            for (int i = m -1; i >= 0; i--) {
                if (board[i][j] != '.') {
                    board[write][j] = board[i][j];
                    if (write != i) board[i][j] = '.';
                    write--;
                }
            }
        }
    }
    
    return answer;
}