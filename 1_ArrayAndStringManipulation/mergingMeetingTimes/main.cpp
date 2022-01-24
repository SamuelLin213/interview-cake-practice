#include <iostream>
#include <iomanip>
#include <vector>
#include "meeting.h"
using namespace std;

vector<Meeting> mergeRanges(vector<Meeting>& meetings)
{
  vector<Meeting> newRanges;

  for(int x = 0; x < meetings.size(); x++)
  {
    // Meeting curr = meetings.at(x);
    Meeting curr;

    for(int n = 0; n < meetings.size(); n++)
    {
      if(n != x)
      {
        if(meetings.at(x).getStartTime() <= meetings.at(n).getStartTime())
        {
          if(meetings.at(x).getEndTime() >= meetings.at(n).getStartTime())
          {
            curr=meetings.at(x);
            int later = (meetings.at(x).getEndTime() > meetings.at(n).getEndTime())
            ? meetings.at(x).getEndTime() : meetings.at(n).getEndTime();
            curr.setEndTime(later);
            meetings.erase(meetings.begin() + n);
          }
        }
        else {
          if(meetings.at(n).getEndTime() >= meetings.at(x).getStartTime())
          {
            curr=meetings.at(n);
            int later = (meetings.at(n).getEndTime() > meetings.at(x).getEndTime())
            ? meetings.at(n).getEndTime() : meetings.at(x).getEndTime();
            curr.setEndTime(later);
            meetings.erase(meetings.begin() + n);
          }
        }
      }
    }
    newRanges.push_back(curr);
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

  allMeetings.push_back(Meeting(0, 1));
  allMeetings.push_back(Meeting(3, 5));
  allMeetings.push_back(Meeting(4, 8));
  allMeetings.push_back(Meeting(10, 12));
  allMeetings.push_back(Meeting(9, 10));

  merged = mergeRanges(allMeetings);
  printRanges(merged);

  return 0;
}
