#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m, k;
int ans = 0;

struct FIREBALL {
    int r, c, mass, s, d;
};

vector<vector<int>> arr; // 파이어볼 위치
vector<FIREBALL> fireball; // 질량과 방향, 속력

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1,- 1};
int dir_1[4] = {0, 2, 4, 6};
int dir_2[4] = {1, 3, 5 ,7};

void input() {
    cin >> n >> m >> k; 
    arr.resize(n + 1, vector<int> (n + 1, 0));
    fireball.resize(m);

    for (int i = 0; i < m; i++) {
        int r, c, mass, s, d;
        cin >> r >> c >> mass >> s >> d;
        arr[r][c] = 1; // 위치 기록
        fireball[i] = {r, c, mass, s, d};
    }
    
}

void move(int num) { // 파이어볼 이동
    int r = fireball[num].r;
    int c = fireball[num].c;
    int m = fireball[num].mass;
    int s = fireball[num].s;
    int d = fireball[num].d;

    arr[r][c] -= 1;
    s = s % n;
    r = (r + dx[d] * s - 1 + n * 1000) % n + 1;
    c = (c + dy[d] * s - 1 + n * 1000) % n + 1;

    arr[r][c] += 1;

    fireball[num].r = r;
    fireball[num].c = c;
    
}

int direction(vector<int> numbers) {
    int isOdd = 0, isEven = 0;

    // 짝수 판별
    for (int i = 0; i < numbers.size(); i++) {
        if (fireball[numbers[i]].d % 2 != 0) {
            isEven = 1;
            break;
        }
    }
    if (isEven == 0) return isEven; // 모두 짝수

    // 홀수 판별
    for (int i = 0; i < numbers.size(); i++) {
        if (fireball[numbers[i]].d % 2 == 0) {
            isOdd = 1;
            break;
        }
    }
    if (isOdd == 0) return isOdd;
    return 1;
}

void assemble(int x, int y) {
    int sum_d = 0, sum_s = 0, sum_m = 0;
    vector<int> numbers;
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        if (fireball[i].r == x && fireball[i].c == y) {
            sum_s += fireball[i].s;
            sum_m += fireball[i].mass;
            numbers.push_back(i); // 제거할 것
            cnt++;
        }
    }

    sum_s /= cnt;
    sum_m /= 5;
    sum_d = direction(numbers);

    for (int i = numbers.size() - 1; i >= 0; i--) {
        fireball.erase(fireball.begin() + numbers[i]);
    }
    m -= numbers.size();


    if (sum_m > 0) {
        // 4개로 분할
        for (int i = 0; i < 4; i++) {
            FIREBALL tmp = {x, y, sum_m, sum_s, (sum_d == 0 ? dir_1[i] : dir_2[i])};
            fireball.push_back(tmp);
        }
        arr[x][y] = 4;
        m += 4;
    }
    else {
        arr[x][y] = 0;
    }

    numbers.clear();
}

void check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] < 2) continue;
            assemble(i, j);
        }
    }
}

void solution() {
    while (k > 0) {
        k--;

        // 이동 명령
        for (int i = 0; i < m; i++) {
            move(i);
        }
        
        // 2개 이상 같은 위치에 존재하는 경우 4개로 분리
        check(); 
    }

    for (int i = 0; i < fireball.size(); i++) {
        ans += fireball[i].mass;
    }
    cout << ans;

}

int main() {
    input();
    solution();
    return 0;

}