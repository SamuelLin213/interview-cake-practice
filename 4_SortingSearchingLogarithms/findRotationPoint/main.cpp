#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
  const vector<string> words {
     "ptolemaic",
     "retrograde",
     "supplant",
     "undulate",
     "xenoepist",
     "asymptote",  // <-- rotates here!
     "babka",
     "banoffee",
     "engender",
     "karpatka",
     "othellolagkage",
  };

  int min = 0, max = words.size()-1;
  int ind = 0;

  while(min < max)
  {
    int mid = min + (max - min)/2;

    if(words[mid] < words[0]) //mid letter is in first half
    {
      max = mid;
    }
    else if(words[mid] >= words[0]) //mid letter is in second half
    {
      min = mid;
    }

    if(min + 1 == max)
    {
      break;
    }
  }
  ind = max;

  cout << "Rotation occurs at index " << ind << " for word " << words[ind] << endl;

  return 0;
}
