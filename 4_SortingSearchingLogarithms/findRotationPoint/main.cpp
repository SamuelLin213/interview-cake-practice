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

  int ind = words.size()/2;

  while(int(words[ind].at(0)) >= 122 && int(words[ind].at(0)) <= 110)
  {
    ind++;
    if(int(words[ind].at(0)) == 97)
      break;
  }
  while(int(words[ind].at(0)) < 110)
  {
    ind--;
  }
  ind++;

  cout << "Rotation occurs at index " << ind << " for word " << words[ind] << endl;

  return 0;
}
