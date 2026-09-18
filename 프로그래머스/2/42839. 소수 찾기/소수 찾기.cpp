#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

map<int, int> m;
bool isPrime(int n) {
    if (n == 0 || n == 1) return false; 
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n != i) return false;
        }
    }
    return true;
}

vector<int> visited;
string number;
void dfs(int cnt, int n, string numbers) {
    visited[n] = 1;
    number = number + numbers[n]; 
    
    for (int i = 0; i < numbers.length(); i++) {
        if (cnt <= number.length()) break;
        if (!visited[i]) {
            dfs(cnt, i, numbers); 
        }
    }
    
    bool prime = isPrime(stoi(number));
    if (prime) {
        m.insert({stoi(number), 0});
    }
    
    visited[n] = 0;
    number.pop_back();
    
}

int solution(string numbers) {
    int answer = 0;
    
    visited.resize(numbers.length());
    
    for (int j = 0; j < numbers.length(); j++) { // 시작 인덱스
        for (int i = 0; i < numbers.length(); i++) { // 길이
            dfs(i + 1, j, numbers);
        }
    }
    
    answer = m.size();
    return answer;
}