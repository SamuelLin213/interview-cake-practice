#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void getMaxProfit(vector<int> &prices)
{
  // int buy, sell;
  // int max = 0;
  if(prices.size() < 2)
  {
    cout << "Error: not enough prices" << endl;
    return;
  }

  int minPrice = prices[0], maxProfit = prices[1] - prices[0];

  for(int x = 1; x < prices.size(); x++)
  {
    if(prices[x] - minPrice > maxProfit)
      maxProfit = prices[x] - minPrice;

    if(prices[x] < minPrice)
      minPrice = prices[x];
  }

  // for(int x = 0; x < prices.size(); x++)
  // {
  //   for(int y = x + 1; y < prices.size(); y++)
  //   {
  //     if(prices[y] - prices[x] > max)
  //       max = prices[y] - prices[x];
  //   }
  // }

  cout << "Max profit: " << maxProfit << endl;
}

int main()
{
  // vector<int> stockPrices{10, 7, 5, 8, 11, 9};
  vector<int> stockPrices{11, 7, 5, 4, 1};

  getMaxProfit(stockPrices);
  // returns 6 (buying for $5 and selling for $11)

  return 0;
}
