#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

// 1, 4, 7 : L
// 3, 6, 9 : R
// 2, 5, 8, 0 : 가까운 쪽

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<vector<int> > keypad;
    keypad = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 2}};

    
    pair<int, int> prevLeft, prevRight, curr;
    prevLeft.first = keypad[10][0]; prevLeft.second = keypad[10][1];
    prevRight.first = keypad[11][0]; prevRight.second = keypad[11][1];
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer+="L";
            prevLeft.first = keypad[numbers[i]][0];
            prevLeft.second = keypad[numbers[i]][1];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer+="R";
            prevRight.first = keypad[numbers[i]][0];
            prevRight.second = keypad[numbers[i]][1];
        }
        else {
            cout << numbers[i] << "\n";
            // 거리 측정
            curr.first = keypad[numbers[i]][0];
            curr.second = keypad[numbers[i]][1];
            
            int distLeft = abs(curr.first - prevLeft.first)+ abs(curr.second - prevLeft.second);
            int distRight = abs(curr.first - prevRight.first)+ abs(curr.second - prevRight.second);
            cout << distLeft << " " << distRight << endl;
            
            if (distLeft < distRight) {
                answer += "L";
                prevLeft.first = keypad[numbers[i]][0];
                prevLeft.second = keypad[numbers[i]][1];
                
            }
            else if (distLeft > distRight) {
                answer += "R";
                prevRight.first = keypad[numbers[i]][0];
                prevRight.second = keypad[numbers[i]][1];
            }
            else {
                if (!strcmp(hand.c_str(), "right")) {
                    answer+="R";
                    prevRight.first = keypad[numbers[i]][0];
                    prevRight.second = keypad[numbers[i]][1];
                    cout << "R" << endl;
                }
                else if (!strcmp(hand.c_str(), "left")) {
                    answer += "L";
                    prevLeft.first = keypad[numbers[i]][0];
                    prevLeft.second = keypad[numbers[i]][1];
                    cout << "L" << endl;
                    
                }
            }
            
        }
    }
    return answer;
}