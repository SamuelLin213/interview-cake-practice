#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool movieSum(int length, vector<int> movies)
{
  unordered_set<int> otherMovies;

  for(int y = 0; y < movies.size(); y++)
  {
    int firstTime = movies[y];
    int secondTime = length - firstTime;
    if(otherMovies.find(secondTime) != otherMovies.end())
      return true;

    otherMovies.insert(movies[y]);
  }

  return false;
}

int main()
{
  int flightLength;
  vector<int> moviesLength;

  

  return 0;
}
