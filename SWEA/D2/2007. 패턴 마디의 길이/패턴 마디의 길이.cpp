#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s;
        cin >> s;
        
        string tmp;
        tmp.push_back(s[0]);
        
        for (int i = 1; i <= s.size(); i++) {
        	if (tmp != s.substr(tmp.size(), i)) {
            	tmp.push_back(s[i]);
            }
            else break;
        }
        
        cout << "#" << test_case << " ";
		cout << tmp.size() << "\n";

	}
	return 0;
}