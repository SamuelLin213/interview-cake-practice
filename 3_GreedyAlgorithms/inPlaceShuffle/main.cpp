#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRand(int start, int end)
{
  return (rand() % (end - start + 1) + start);
}

int main(){
  srand(time(0));
  vector<int> nums = {3, 5, 1, 7, 10};

  for(int x = 0; x < nums.size(); x++)
  {
    int ind = getRand(x, nums.size()-1);
    int temp = nums[x];
    nums[x] = nums[ind];
    nums[ind] = temp;
  }

  for(int x = 0; x < nums.size(); x++)
  {
    cout << nums[x] << " ";
  }
  cout << endl;

  return 0;
}
