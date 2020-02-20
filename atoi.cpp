#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int myAtoi(string str) {
  // Find the first non-whitespace character.
  int i = 0;
  while (i < str.length()) {
    if (str[i] == ' ') {
      i++;
    }
    else {
        break;
    }
  }

  // Early exit if the character is not a number or the sign.
  int sign = 1;
  if (str[i] == '-') {
    sign = -1;
    i++;
  } else if (str[i] == '+') {
    i++;
  } else if (str[i] < '0' || str[i] > '9') {
    return 0;
  }

  double result = 0;
  while ((i < str.length()) && str[i] >= '0' && str[i] <= '9') {
    result = result * 10 + str[i] - '0';
    i++;
    if (result > INT_MAX) {
      if (sign < 0) {
          return INT_MIN;
      }
      else {
        return INT_MAX;
      }
    }
  }

  int intResult = static_cast<int>(result) * sign;
  return intResult;
}

int main() {
  //string input = "+42";
  //  string input = "-91283472332";
  string input = "2147483646";
  cout << myAtoi(input) << endl;
  return 0;
}
