#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
struct CharToInt {
  char c; int val;  
};

string intToRoman(int num) {
        unordered_map<int, string> negativeCases = {
            {4, "IV"}, {9, "IX"},{40, "XL"},{90, "XC"},{400, "CD"},{900, "CM"},
        };
        vector<CharToInt> romans = {
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1},
        };
        string result = "";
        int digit = 1000;
        
        while (digit) {
          int curNum = num / digit;
            curNum *= digit;
            num -= curNum;

            // Deal with special cases here
            auto it =  negativeCases.find(curNum);
            if (it != negativeCases.end()) {
                result += it->second;
                curNum = 0;
            }
            
            int curDiv = 0;
            while (curNum) {
                while (curNum / romans[curDiv].val) {
                    for (int i = 0; i < curNum/romans[curDiv].val; i++) {
                        result += romans[curDiv].c;
                    }                    
                    curNum %= romans[curDiv].val;
                }
                curDiv++;                
            }
            
            digit /= 10;
        }
        
        return result;
    }

int main()
{
  int num = 1994;
  cout << intToRoman(num) << endl;
  return 0;
}
