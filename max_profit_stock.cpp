#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
  vector<double>  prices = {300, 310, 310, 275, 275, 260, 260, 230, 230, 230 };

  double minSoFar = numeric_limits<double>::max();
  double maxProfit = 0;
  for (auto price : prices) {
    double maxProfitToday = price - minSoFar;
    maxProfit = max(maxProfitToday, maxProfit);
    minSoFar = min(minSoFar, price);
  }

  cout << "Max Profit: "<< maxProfit;
  return 0;
}
