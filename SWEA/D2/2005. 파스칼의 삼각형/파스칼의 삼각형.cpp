#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
        vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
        cout << "#" << test_case << "\n";   
        for (int i = 0; i < n; i++) {
        	for (int j = 0; j < i+1; j++) {
                if (i ==j || j == 0) {
                	cout << 1 << " ";
                }
                else {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}