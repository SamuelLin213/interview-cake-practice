#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printVec(vector<int> &vec)
{
  for(int x = 0; x < vec.size(); x++)
  {
    cout << vec[x] << " ";
  }
  cout << endl;
}
vector<int> getProductsOfAllIntsExceptAtIndex(vector<int> &intVector)
{
  vector<int> products(intVector.size());

  int productSoFar = 1;
  for (int i = 0; i < intVector.size(); ++i) {
    products[i] = productSoFar;
    productSoFar *= intVector[i];
  }
  productSoFar = 1;
  int ind = 0;
  for(int i = intVector.size()-1; i >= 0; i--)
  {
    products[i] *= productSoFar;
    productSoFar *= intVector[i];
  }

  return products;
}

int main()
{
  vector<int> intVector = {1, 2, 6, 5, 9};

  vector<int> products = getProductsOfAllIntsExceptAtIndex(intVector);

  printVec(products);

  // cout << "Before: " << endl;
  // printVec(before);
  //
  // cout << endl;
  // cout << "After: " << endl;
  // printVec(after);

  return 0;
}
