#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
  vector<int> takeOut = {1, 3, 5};
  vector<int> dineIn = {2, 4, 6};
  vector<int> served = {1, 2, 4, 6, 3, 5};
  bool ordered = true;

  int takeOutInd = 0, dineInInd = 0;

  for(int x = 0; x < served.size()-1; x++)
  {
    if(takeOutInd < takeOut.size() && served[x] == takeOut[takeOutInd])
    {
      takeOutInd++;
    }
    else if(dineInInd < dineIn.size() && served[x] == dineIn[dineInInd])
    {
      dineInInd++;
    }
    else {
      ordered = false;
      break;
    }
  }

  if(ordered)
  {
    cout << "Served orders are in the right order" << endl;
  }
  else
    cout << "Served orders are not in the right order" << endl;

  return 0;
}
