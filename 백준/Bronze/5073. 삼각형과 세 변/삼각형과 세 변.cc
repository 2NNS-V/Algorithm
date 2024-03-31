#include <iostream>
#include <algorithm>

using namespace std;

int check(int a, int b, int c) {
   int max_value = max({a, b, c});
   if ((max_value == a && max_value >= b + c) || (max_value == b && max_value >= a+c) || (max_value == c && max_value >= a+ b)) {
    return 0;
   }
   return 1;
}

int main() {
    int a, b, c;
    while (1) {
        cin >> a >> b >>c ;
        if (!a && !b && !c) break;
        int checked = check(a, b, c);

        if (a == b && a == c && b == c) cout << "Equilateral" << "\n";
        else if (checked == 0) cout << "Invalid" << "\n";
        else if (a != b && b != c && c != a) cout << "Scalene" << "\n";
        else if ((a== b && b != c) || (a == c && c != b) || (b == c && b != a)) cout << "Isosceles" << "\n";
    }
}