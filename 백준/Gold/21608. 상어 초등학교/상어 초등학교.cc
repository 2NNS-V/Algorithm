#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

typedef struct SEAT {
    int x;
    int y;
    int like;
    int empty;
}SEAT;

vector<vector<int>> arr;
vector<int> seq;
vector<vector<int>> seat;
vector<SEAT> best;


bool compare(const SEAT& a, const SEAT& b) {
    // 좋아하는 학생 수, 빈칸 수, 행, 열 우선순위 대로 return
    if (a.like != b.like) return a.like > b.like;
    if (a.empty != b.empty) return a.empty > b.empty;
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int count_like(int x, int y, int student_num) {
    int like = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            for (int j = 0; j < 4; j++) {
                if (arr[student_num][j] == seat[nx][ny]) {
                    like++;
                    break;
                }
            } 
        }
    }
    return like;
}

int count_empty(int x, int y) {
    int empty = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            if (seat[nx][ny] == 0) empty++;
        }
    }
    return empty;
}

void place(int student_num) {
    // TODO: 특정 칸에 학생을 놓고 주변 빈 칸, 친구 수 세기

    SEAT tmp; 
    best.clear();

    // 후보군 push
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (seat[i][j] == 0) {
                tmp = {i, j, count_like(i, j, student_num), count_empty(i, j)};
                best.push_back(tmp); // 후보 업데이트
            }
        }
    } 

    // 주변 빈칸, 친구수 정렬
    sort(best.begin(), best.end(), compare);
    seat[best.front().x][best.front().y] = student_num;
}

int calc() {
    // 만족도 계산
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int student = seat[i][j];
            int like = count_like(i, j, student);
            score += pow(10, like - 1);
        }
    }
    return score;
}

void input() {
    cin >> n;
    arr.resize(n*n + 1, vector<int> (4, 0));
    seat.assign(n, vector<int> (n, 0));

    for (int i = 0; i < n * n; i++) {
        int num = 0;
        cin >> num;
        seq.push_back(num);

        for (int j = 0; j < 4; j++) {
            cin >> arr[num][j];
        }
    }
}

int main() {
    input();

    for (int i = 0; i < n*n; i++) {
        place(seq[i]); // 최적 후보
    }
    
    cout << calc();
}