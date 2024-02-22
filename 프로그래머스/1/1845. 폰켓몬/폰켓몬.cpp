#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0; 
    sort(nums.begin(), nums.end());
    answer = nums.size();

    for (int i=1;i<nums.size();i++) {
        if (nums[i-1] == nums[i]) answer--;
    }
    if (answer >= nums.size()/2) answer = nums.size()/2;
    return answer;
}