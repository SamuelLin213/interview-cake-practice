#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

void printMap(unordered_map<string, int> const &wordMap)
{
  for (auto const &pair: wordMap) {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
  }
}

int main()
{
  unordered_map<string, int> words;
  vector<char> goodChar = {'-', '\''};
  string str;
  vector<char> strChars;

  cout << "Enter a string here: ";
  getline(cin, str);

  int index = 0;
  while(index < str.length())
  {
    if((int(str.at(index)) >= 65 && (int(str.at(index)) <= 90)) ||
    (int(str.at(index)) >= 97 && int(str.at(index)) <= 122) ||
    find(goodChar.begin(), goodChar.end(), str.at(index)) != goodChar.end())
    {
      while((int(str.at(index)) >= 65 && (int(str.at(index)) <= 90)) ||
      (int(str.at(index)) >= 97 && int(str.at(index)) <= 122) ||
      find(goodChar.begin(), goodChar.end(), str.at(index)) != goodChar.end())
      {
        char tempCh = str.at(index);
        if(int(tempCh) < 97)
          tempCh = tolower(tempCh);
        strChars.push_back(tempCh);

        index++;

        if(index >= str.length())
          break;
      }

      string nextWord(strChars.begin(), strChars.end());
      if(words.find(nextWord) == words.end())
      {
        words.insert(make_pair(nextWord, 1));
      }
      else{
        words.find(nextWord)->second += 1;
      }

      nextWord = "";
      strChars.clear();
    }
    else{
      index++;
    }

    // if(index >= str.length())
    //   break;
    // while( int(str.at(index)) < 65 || int(str.at(index)) > 122 ||
    // (int(str.at(index)) > 132 && int(str.at(index)) < 97) )
    // {
    //   index++;
    //   if(index >= str.length())
    //   {
    //     break;
    //   }
    // }
  }

  printMap(words);

  return 0;
}
