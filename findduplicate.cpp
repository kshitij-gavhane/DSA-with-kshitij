#include <bits/stdc++.h>
using namespace std;
class solution{
  public:
  int
  findduplicate(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    for (int i =1;i<nums.size();i++){
      if(nums[i]==nums[i-1])
      return nums[i];
    }
    return -1;
  }
};