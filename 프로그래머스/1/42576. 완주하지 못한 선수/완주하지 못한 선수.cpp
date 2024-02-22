#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    int Psize = participant.size();
    int Csize = completion.size();
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int i = 0;
    for (;i<Csize;i++) {
        if (participant[i] != completion[i]) 
            break;
    } 
    answer = participant[i]; 
    return answer;
}