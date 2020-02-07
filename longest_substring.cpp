#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    int longest = 0;
    std::unordered_set<char> charsSeen;

    while (j < s.size()) {
        i = j;
        int curLongest = 0;
        while (i < s.size()) {
            auto found = charsSeen.find(s[i]);
            if (found == charsSeen.end()) {
                charsSeen.insert(s[i]);
                curLongest++;
            }
            else {
                charsSeen.clear();
                break;
            }

            longest = max(curLongest, longest);
            i++;
        }
        j++;
    }
    return longest;
}


int main(int argc, char ** argv)
{

  std::string s = "bbcabcdrrrrrr";
  cout << s.size() << endl;
  std::cout << "longest: "<< lengthOfLongestSubstring(s) << std::endl;
  return 0;
}
