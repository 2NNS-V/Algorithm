#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first < b.first;
}

int main() {
    int n; cin >> n;
    vector<pair<int, string> > people;

    for (int i = 0; i < n; i++) {
        int age; string name; 
        cin >> age >> name;
        people.push_back(make_pair(age, name));
    }

    stable_sort(people.begin(), people.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << people[i].first << " " << people[i].second << endl;
    }
}