#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  vector<string> columns = {
    "AA", "ZZZZ", "AZ", "A", "B", "Y"
  };

  for (auto& str : columns) {
    int result = 0;    
    for (auto& ch : str) {
      result = result * 26 + ch - 'A' + 1;
    }
    cout << str << " " <<  result << endl;
  }
  
  return 0;
}
