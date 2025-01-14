#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> uniqueSums;
    int n = elements.size();

    vector<int> arr(2 * n);  // To handle circular array
    for (int i = 0; i < n; i++) {
        arr[i] = elements[i];
    }
    for (int i = n; i < 2 * n; i++) {
        arr[i] = elements[i - n];
    }

    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < start + n; end++) {
            sum += arr[end];
            uniqueSums.insert(sum);
        }
    }

    return uniqueSums.size();
}
