#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count_one(const string &str) {
    int cnt = 0;
    for (auto c: str) {
        if (c == '1') cnt++;
    }
    return cnt;
}

string to_binary(int n) {
    string binary = "";
    while (n) {
        binary = (n % 2 == 0 ? '0' : '1') + binary;
        n /= 2;
    }
    return binary;
}

int solution(int n) {
    int answer = 0;
    // 조건1: n보다 큼
    // 조건2: 2진수로 변환했을 때 1의 개수가 같음
    // 조건3: 조건1, 2를 만족하는 수 중에서 가장 작은 수
    
    int n_cnt = count_one(to_binary(n));
    
    while (1) {
        if (n > 1000000) break;
        // 2진수로 변환
        int tmp = ++n;
        string binary = to_binary(tmp);

        // 1개 개수 카운트
        if (count_one(binary) == n_cnt) {
            answer = tmp;
            break;
        }
    }
    
    return answer;
}