#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> s;
    int size = elements.size();
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < i + size; j++) {
            int index = j % size;
            sum += elements[index];
            s.insert(sum);
        }
    }
    answer = s.size();
    return answer;
}