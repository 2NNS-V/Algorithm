#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer; vector<int> num;
    int tmp;
    
    answer.push_back(arr[0]);
    num.push_back(arr[0]);
    for (int i = 1; i < arr.size(); ++i) {
        tmp = num.back();
        num.pop_back();
        if (tmp != arr[i]) {
            answer.push_back(arr[i]);
        }
        num.push_back(arr[i]);
    } 

    return answer;
}