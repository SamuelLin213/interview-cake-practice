#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

void reverseWords(string& str)
{
  istringstream strStm(str);
  ostringstream oStream;
  string tempStr;
  vector<string> words;

  while(strStm >> tempStr)
  {
    words.push_back(tempStr);
  }

  for(int x = words.size() - 1; x > 0; x--)
  {
    oStream << words.at(x) << " ";
  }
  oStream << words.at(0);

  str = oStream.str();
}

int main()
{
  string message = "cake pound steal";

  reverseWords(message);

  cout << message << endl;

  return 0;
}
