#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
    int max_value = max(a, b);
    int min_value = min(a, b);
    
    while (max_value % min_value != 0) {
        int rest = max_value % min_value;
        max_value = min_value;
        min_value = rest;
    }
    return min_value;
}

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int gcd = GCD(arr[i], answer);
        int lcd = answer * arr[i] / gcd;
        answer = lcd;
    }
    
    return answer;
}