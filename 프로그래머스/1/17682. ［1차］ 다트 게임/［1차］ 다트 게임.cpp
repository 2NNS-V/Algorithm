#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// * : 점수와 그 전에 점수를 2배
// # : -점수
int solution(string dartResult) {
    int answer = 0;
    vector<int> score(3);
    vector<char> bonus(3);
    vector<char> option(3, '0');
    
    int n = dartResult.size();
    int k = 0, p = 0, r = 0;
    while(k < n) {
        if (dartResult[k] == '*' || dartResult[k] == '#') {
            option[p - 1] = dartResult[k];
            k++;  
        }
        else if (dartResult[k] == 'S' || dartResult[k] == 'D' || dartResult[k] == 'T') {
            bonus[p] = dartResult[k];
            p++;
            k++; 
        }
        else if (dartResult[k] >= '0' && dartResult[k] <= '9') {
            if (dartResult[k+1] == '0') {// 10인 경우
                score[r] = 10;
                k += 2; 
            }
            else {
                score[r] = dartResult[k] - '0';
                k++;
            }
            r++;
            
        }   
        
    }
    
    
    // score = [1, 2, 3]
    // bonus = ['S', 'S', 'S']
    // option = ['', '*', '']
    for (int i = 0; i < 3; i++) {
        if (bonus[i] == 'D') score[i] = pow(score[i], 2);
        else if (bonus[i] == 'T') score[i] = pow(score[i], 3);
    }
    
    for (int i = 0; i < 3; i++) {
        cout << option[i] << " ";
        
        if (option[i] == '*') {
            score[i] *= 2;
            if (i != 0) score[i-1] *= 2;
        }
        else if (option[i] == '#') score[i] *= -1;
    }
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << score[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << bonus[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << option[i] << " ";
    }
    cout << endl;
     
    for (int i = 0; i < 3; i++) {
        answer += score[i];
    }
    return answer;
}