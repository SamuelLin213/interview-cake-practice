#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeVectors(const vector<int> vec1, const vector<int> vec2) { //merges subarrays
  int ind1 = 0;
  int ind2 = 0;
  vector<int> mergedVec;

  while(ind1 < (int)vec1.size() && ind2 < (int)vec2.size())
  {
    if(vec1[ind1] <= vec2[ind2])
    {
      mergedVec.push_back(vec1[ind1]);
      ind1++;
    }
    else
    {
      mergedVec.push_back(vec2[ind2]);
      ind2++;
    }
  }

  while(ind1 < (int)vec1.size())
  {
    mergedVec.push_back(vec1[ind1]);
    ind1++;
  }
  while(ind2 < (int)vec2.size())
  {
    mergedVec.push_back(vec2[ind2]);
    ind2++;
  }

  return mergedVec;
}


int main()
{
  const vector<int> myVector {3, 4, 6, 10, 11, 15};
  const vector<int> alicesVector {1, 5, 8, 12, 14, 19};

  vector<int> mergedVector = mergeVectors(myVector, alicesVector);

  cout << "[";
  for (size_t i = 0; i < mergedVector.size(); ++i) {
    if (i > 0) {
        cout << ", ";
    }
    cout << mergedVector[i];
  }
  cout << "]" << endl;
  // prints [1, 3, 4, 5, 6, 8, 10, 11, 12, 14, 15, 19]
}
