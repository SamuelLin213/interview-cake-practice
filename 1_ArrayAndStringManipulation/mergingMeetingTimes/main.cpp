#include <iostream>
#include <iomanip>
#include <vector>
#include "meeting.h"
using namespace std;

void sortMeetings(vector<Meeting>& meetings)
{
  for(int x = 0; x < meetings.size(); x++)
  {
    int swapPos;
    int smallPos = x;

    for(int n = x+1; n < meetings.size(); n++)
    {
      if(meetings.at(n).getStartTime() < meetings.at(smallPos).getStartTime())
      {
        smallPos = n;
      }
    }
    Meeting temp = meetings.at(smallPos);
    meetings.at(smallPos) = meetings.at(x);
    meetings.at(x) = temp;
  }
}

vector<Meeting> mergeRanges(vector<Meeting>& meetings)
{
  vector<Meeting> newRanges;
  newRanges.push_back(meetings.front());

  for(int x = 0; x < meetings.size()-1; x++)
  {
    // O(n) method: vector already sorted
    if(newRanges.back().getEndTime() >= meetings.at(x).getStartTime())
    {
      if(meetings.at(x).getEndTime() > newRanges.back().getEndTime())
      {
        newRanges.back().setEndTime(meetings.at(x).getEndTime());
      }
    }
    else {
      newRanges.push_back(meetings.at(x));
    }

    // O(n^2) method; goes through each meeting and compares with all other ones to find ones to merge with
    // Meeting curr;
    //
    // for(int n = 0; n < meetings.size(); n++)
    // {
    //   if(n != x)
    //   {
    //     if(meetings.at(x).getStartTime() <= meetings.at(n).getStartTime())
    //     {
    //       if(meetings.at(x).getEndTime() >= meetings.at(n).getStartTime())
    //       {
    //         curr=meetings.at(x);
    //         int later = (meetings.at(x).getEndTime() > meetings.at(n).getEndTime())
    //         ? meetings.at(x).getEndTime() : meetings.at(n).getEndTime();
    //         curr.setEndTime(later);
    //         meetings.erase(meetings.begin() + n);
    //       }
    //     }
    //     else {
    //       if(meetings.at(n).getEndTime() >= meetings.at(x).getStartTime())
    //       {
    //         curr=meetings.at(n);
    //         int later = (meetings.at(n).getEndTime() > meetings.at(x).getEndTime())
    //         ? meetings.at(n).getEndTime() : meetings.at(x).getEndTime();
    //         curr.setEndTime(later);
    //         meetings.erase(meetings.begin() + n);
    //       }
    //     }
    //   }
    // }
    // newRanges.push_back(curr);
  }

  return newRanges;
}

void printRanges(vector<Meeting> meetings)
{
  for(int x = 0; x < meetings.size(); x++)
  {
    cout << meetings.at(x).getStartTime() << " " << meetings.at(x).getEndTime() << endl;
  }
}

int main()
{
  vector<Meeting> allMeetings;
  vector<Meeting> merged;

  //Test 1
  // allMeetings.push_back(Meeting(0, 1));
  // allMeetings.push_back(Meeting(3, 5));
  // allMeetings.push_back(Meeting(4, 8));
  // allMeetings.push_back(Meeting(10, 12));
  // allMeetings.push_back(Meeting(9, 10));

  //Test 2
  allMeetings.push_back(Meeting(1, 10));
  allMeetings.push_back(Meeting(2, 6));
  allMeetings.push_back(Meeting(3, 5));
  allMeetings.push_back(Meeting(7, 9));

  sortMeetings(allMeetings);
  printRanges(allMeetings);

  cout << endl;

  merged = mergeRanges(allMeetings);
  printRanges(merged);

  return 0;
}
