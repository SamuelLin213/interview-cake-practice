#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

void insertInPlace(int arr[], int val, int code)
{
    int index = 1;

    if(code == 1)
    {
      while(index >= 0 && val > arr[index])
      {
        index--;
      }
    }
    else if(code == 2)
    {
      while(index >= 0 && val < arr[index])
      {
        index--;
      }
    }
    index++;

    for(int x = 1; x > index; x--)
    {
      arr[x] = arr[x-1];
    }
    arr[index] = val;
    cout << "Curr: " << arr[0] << " " << arr[1] << endl;
}

int main()
{
  vector<int> nums = {-10, -10, 1, 3, 2};

  // int arr[4] = {0};
  //
  // arr[0] = nums[0];

  int pos[3] = {0};
  int neg[3] = {0};
  int product = 0;

  for(int i = 0; i < nums.size(); i++)
  {
    if(nums[i] * pos[0] * pos[1] > product)
    {
      product = nums[i] * pos[0] * pos[1];
    }
    else if(nums[i] * neg[0] * neg[1] > product)
    {
      product = nums[i] * neg[0] * neg[1];
    }
    if(nums[i] > 0)
    {
      insertInPlace(pos, nums[i], 1);
    }
    else if(nums[i] < 0)
    {
      insertInPlace(neg, nums[i], 2);
    }
  }

  cout << "The maximum product: " << product << endl;

  return 0;
}
