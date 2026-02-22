#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <utility>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void R(vector<vector<int>>& arr) {
    int col = arr[0].size(); 
    int row = arr.size();
    int max_col = INT_MIN;

    vector<vector<int>> tmp(100, vector<int> (100,0));

    for (int i = 0; i < row; i++) {
        map<int, int> m;

        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 0) continue;
            m[arr[i][j]]++;
        }

        // map 정렬
        vector<pair<int, int>> m_arr(m.begin(), m.end());
        sort(m_arr.begin(), m_arr.end(), compare);

        if (max(max_col, (int)m.size() * 2) < 100)  
            max_col = max(max_col, (int)m.size() * 2); // first, second
        else max_col = 100;

        int k = 0;
        for (auto data : m_arr) {
            // 순서대로 tmp에 집어 넣기
            tmp[i][k++] = data.first;
            tmp[i][k++] = data.second;
        }
    }

    arr.resize(row);
    for (int i = 0; i < row; i++) {
        arr[i].resize(max_col);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < max_col; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void C(vector<vector<int>>& arr) {
    int col = arr[0].size(); 
    int row = arr.size();
    int max_row = INT_MIN;
    vector<vector<int>> tmp(100, vector<int> (100, 0));

    for (int i = 0; i < col; i++) {
        map<int, int> m;

        for (int j = 0; j < row; j++) {
            if (arr[j][i] == 0) continue;
            if (m.find(arr[j][i]) != m.end()) m[arr[j][i]]++;
            else m.insert({arr[j][i], 1});
        }

        // map 정렬
        vector<pair<int, int>> m_arr(m.begin(), m.end());
        sort(m_arr.begin(), m_arr.end(), compare);

        if (max(max_row, (int)m.size() * 2) < 100) 
            max_row = max(max_row, (int)m.size() * 2);
        else max_row = 100;

        int k = 0;
        for (auto data : m_arr) {
            // 순서대로 tmp에 집어 넣기
            tmp[k++][i] = data.first;
            tmp[k++][i] = data.second;
        }
    }

    arr.resize(max_row);
    for (int i = 0; i < max_row; i++) {
        arr[i].resize(col);
    }

    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

int main() {
    int r, c, k;
    vector<vector<int>> arr(3, vector<int> (3, 0));
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int t = 0, cnt = 0;
    int row = arr.size(), col = arr[0].size();

    while (t <= 100) {
        if (r-1 < row && c-1 < col && arr[r-1][c-1] == k) {
            cout << t;
            return 0;
        }

        if (row>=col) R(arr);
        else C(arr);
        
        row = arr.size(), col = arr[0].size();
        t++; 
    }
    cout << -1;

}