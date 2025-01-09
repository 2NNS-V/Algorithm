#include <string>
#include <vector>
#include <iostream>

using namespace std;

int count_one(int n) {
    int cnt = 0;
    while (n) {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

// n보다 큰 것 중 2진수 변환시 1의 개수가 같은 것 중 가장 작은 수
int solution(int n) {
    int answer = 0;
    int n_cnt = count_one(n);
    
    int number = n + 1; 
    while (count_one(number) != n_cnt) {
        number++;
    }
    answer = number;
    return answer;
}