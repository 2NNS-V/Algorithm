#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 2개씩 나누는 함수
void split(string& str, vector<string>& subset) {
    for (int j = 0; j < str.size() - 1; j++) {
        char c1 = str[j];
        char c2 = str[j + 1];

        if (isalpha(c1) && isalpha(c2)) {
            string st;
            st.push_back(tolower(c1));
            st.push_back(tolower(c2));

            subset.push_back(st);
        }
    }
}
   
            
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> subset1;
    vector<string> subset2;
    
    split(str1, subset1); split(str2, subset2);
    sort(subset1.begin(), subset1.end()); sort(subset2.begin(), subset2.end());
    
    vector<string> union_sub; vector<string> intersection_sub;
    set_union(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), back_inserter(union_sub));
    
    set_intersection(subset1.begin(), subset1.end(), subset2.begin(), subset2.end(), back_inserter(intersection_sub));
    
    int inter = intersection_sub.size(); int uni = union_sub.size();
    // 둘 다 공집합인 경우
    if (uni == 0) return 65536;  

    double jaccard = (double)inter / uni;

    return (int)(jaccard * 65536);
}