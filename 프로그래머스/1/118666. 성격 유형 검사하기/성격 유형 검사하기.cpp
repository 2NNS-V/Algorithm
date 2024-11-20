#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 매우 동의, 비동의 = 3
// 동의, 비동의 = 2
// 약간 동의, 비동의 = 1
// 모르겠음 = 0

int scores[] = {3, 2, 1, 0, 1, 2, 3};
vector<vector<int> > arr(4, vector<int> (2, 0));
vector<vector<char> > types = {{'R', 'T'}, {'F', 'C'}, {'M', 'J'}, {'N', 'A'}};

pair<int, int> index(char ch) {
    switch(ch) {
        case 'R': return {0, 0};
        case 'T': return {0, 1};
        case 'F': return {1, 0};
        case 'C': return {1, 1};
        case 'M': return {2, 0};
        case 'J': return {2, 1};
        case 'N': return {3, 0};
        case 'A': return {3, 1};
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for (int i = 0; i < survey.size(); i++) {
        string tmp = survey[i];
        pair<int, int> value;
        if (choices[i] >= 1 && choices[i] <= 3) 
            value = index(tmp[0]);
        else if (choices[i] >= 5 && choices[i] <= 7) 
            value = index(tmp[1]);
        else continue;
        arr[value.first][value.second] += scores[choices[i] - 1];
    }
    cout << (int)'T' << (int)'R';

    for (int i = 0; i < 4; i++) {
        if (arr[i][0] < arr[i][1]) answer += types[i][1];
        else if (arr[i][0] > arr[i][1]) answer += types[i][0];
        else {
            if ((int)types[i][0] < (int)types[i][1]) answer += types[i][0];
            else answer += types[i][1];
        }
    }
    return answer;
}