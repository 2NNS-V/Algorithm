#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector <int>> tmp1(n+1, vector<int>(n+1)); vector<vector<int>> tmp2(n+1, vector<int>(n+1));
    
    int num;
    for (int i =0; i < n;i++) {
        num = arr1[i];
        for (int j = 0; j<n;j++) {
            tmp1[i][j] = num % 2;
            num /= 2;
        }
    }
    
    
    for (int i =0; i < n;i++) {
        num = arr2[i];
        for (int j = 0; j<n;j++) {
            tmp2[i][j] = num % 2;
            num /= 2;
        }
    }
    
    string tmp;
    
    for (int i=0;i< n;i++) {
        for (int j=n-1;j>=0;j--) {
            if (tmp1[i][j] == 1 || tmp2[i][j] == 1)
                tmp += "#";
            else if (tmp1[i][j] == 0 && tmp2[i][j] == 0)
                tmp += " ";
        }
        answer.push_back(tmp);
        tmp = "";
    }

    return answer;
}