#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double n; cin >> n;
    double sum = 0;

    vector<double> score(n+1, 0);
    double MAX = -100000.0;
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        if (MAX < score[i]) MAX = score[i];
    }

    for (int i = 0; i < n; i++) {
        score[i] = score[i] / MAX * 100.0;
        sum += score[i];
    }

    cout << sum / n;
    
}
