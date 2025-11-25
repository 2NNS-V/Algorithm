#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n+1, 0);
    vector<char> ans;
    stack<int> st;

    bool possible = true;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr[i] = tmp;
    }

    
    int i = 1;
    for (int j = 0; j < n; j++) { 
        int target = arr[j];

        while (i <= target) {
            st.push(i++);
            ans.push_back('+');
        }

        if (st.empty() || st.top() != target) {
            possible = false;
            break;
        }

        st.pop();
         ans.push_back('-');
    }

    if (!possible) {
        cout << "NO"; 
    }
    else {
        for (auto c: ans) {
            cout << c << "\n";
        }
    }
}