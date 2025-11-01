/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    long long n; cin >> n;
    vector<pair<long long, long long>> time;
    for (int i = 0; i < n; i++) {
        // 회의 정보(시작 시간, 끝나는 시간)
        int start, end; cin >> start >> end;
        time.push_back(make_pair(start, end));
    }
    
    sort(time.begin(), time.end(), compare);
    
    int ans = 0;
    int last = 0;
    
    for (int i = 0; i < time.size(); i++) {
        if (time[i].first >= last) {
            ans++; last = time[i].second;
        }
    }
    
    cout << ans << endl;
    
    
    
    

    return 0;
}