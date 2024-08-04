#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int n;
    cin >> n;
    
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    
    for (int i = 0; i < n;i++) {
        int number;
        cin >> number;
        
        if (maxQ.empty() || maxQ.size() == minQ.size()) {
            maxQ.push(number);
        }
        else {
            minQ.push(number);
        }

        if (!maxQ.empty() && !minQ.empty() && maxQ.top() > minQ.top()) {
            int x = maxQ.top();
            int y = minQ.top();

            maxQ.pop(); minQ.pop();
            maxQ.push(y); minQ.push(x);
        }

        cout << maxQ.top() << "\n";
    }
    return 0;
}