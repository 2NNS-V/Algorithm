#include <iostream>

using namespace std;

char star[3072][6144];
void print(int n, int x, int y);
int main() {
    int n; cin >> n;
    
    for (int i =0 ; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            star[i][j] = ' ';
        }
    }

    print(n, n-1, 0);

    for (int i =0 ; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << star[i][j];
        }
        cout << "\n";
    }
}   

void print(int n, int x, int y) {
    if (n == 3) {
        star[y][x] = '*';

        star[y+1][x-1] = '*';
        star[y+1][x+1] = '*';

        star[y+2][x-2] = '*';
        star[y+2][x-1] = '*';
        star[y+2][x] = '*';
        star[y+2][x+1] = '*';
        star[y+2][x+2] = '*';
        return ;
    }
    print(n/2, x,  y);
    print(n/2, x - n/2, y + n/2 );
    print(n/2, x + n/2, y + n/2 );
}