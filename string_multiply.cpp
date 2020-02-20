#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string num1 = "123";
  string num2 = "456";

  string result(num1.length() + num2.length(), '0');
        
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                const char curChar = result[i+j+1];
                int cur = curChar - '0';

                const char n1 = num1[i];
                const char n2 = num2[j];
                int a = n1 - '0'; int b = n2 - '0';
                cur += a * b;
                
                const char prevChar = result[i + j];
                int prev = prevChar - '0';
                prev += cur / 10;
                
                cur %= 10;
                
                result[i+j+1] = '0' + cur;
                result[i+j] = '0' + prev;
                
                //result[i + j + 1] = atoi(&result[i + j + 1]) + atoi(&num1[i]) * atoi(&num2[j]);
                //result[i + j] += result[i + j + 1] / 10;
                //result[i + j + 1] %= 10;
            }
        }
        result = {
            find_if_not(begin(result), end(result), [](char a) { return a == '0';}),
            end(result)
        };


        for (auto c : result) {
          cout << c;
        }

        
        
        return 0;
}
