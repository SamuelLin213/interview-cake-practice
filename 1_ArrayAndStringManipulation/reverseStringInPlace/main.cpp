#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void reverseString(string& str)
{
  for(int x = 0; x < str.length()/2; x++)
  {
    char temp = str[x];
    str[x] = str[str.length() - x - 1];
    str[str.length() - x - 1] = temp;
  }
}

int main()
{
  string str = "Hello";

  reverseString(str);

  cout << str;

  return 0;
}
