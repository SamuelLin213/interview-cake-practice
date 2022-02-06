#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void print_map(unordered_map<char, int> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

int main()
{
  unordered_map<char, int> palindrome;
  unordered_set<char> counts;
  string str;
  char middle;
  bool palin = true;
  int odd = 0;

  cout << "Enter a string: ";
  cin >> str;

  //First solution: Brute Force
  // for(int x = 0; x < str.length(); x++)
  // {
  //   auto it = palindrome.find(str[x]);
  //   if(it != palindrome.end())
  //   {
  //     palindrome[str[x]] += 1;
  //   }
  //   else{
  //     palindrome.insert(make_pair(str[x], 1));
  //   }
  // }
  //
  // print_map(palindrome);
  //
  // // unordered_map<int, int>::iterator it;
  // //it = palindrome.begin(); it != palindrome.end(); it++
  // for(auto it: palindrome)
  // {
  //     if(it.second % 2 != 0)
  //     {
  //       odd++;
  //     }
  //     if(odd > 1)
  //     {
  //       palin = false;
  //       break;
  //     }
  // }
  //
  // cout << "The string " << str << " is" << ((palin) ? " " : " not ") << "a palindrome." << endl;

  //Second solution: Using set
  for(int x = 0; x < str.length(); x++)
  {
    if(counts.find(str[x]) == counts.end())
    {
        counts.insert(str[x]);
    }
    else{
      counts.erase(counts.find(str[x]));
    }
  }

  cout << "The string " << str << " is" << ((counts.size() <= 1) ? " " : " not ") << "a palindrome." << endl;

  return 0;
}
