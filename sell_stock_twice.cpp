#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
  cout << "Computes the maximum profit if we must buy and sell a stock twice over a period." << endl;
  vector<int> prices = {12, 11, 13, 9, 12, 8, 14, 13, 15};

  int maxProfitSoFar = 0;
  int minPriceSoFar = numeric_limits<int>::max();
  vector<int> forwardMaxProfit(size(prices), 0);

  // Forward iteration.
  for (int i = 0; i < size(prices); i++) {
    minPriceSoFar = min(minPriceSoFar, prices[i]);
    maxProfitSoFar = max(prices[i] - minPriceSoFar, maxProfitSoFar);
    forwardMaxProfit[i] = maxProfitSoFar;
  }

  int maxTotalProfit = maxProfitSoFar;
  maxProfitSoFar = numeric_limits<int>::min();
  // Backward iteration.
  for (int i = size(prices) - 1; i > 0; i--) {
    maxProfitSoFar = max(maxProfitSoFar, prices[i]);
    maxTotalProfit = max(maxProfitSoFar - prices[i] + forwardMaxProfit[i-1], maxTotalProfit);
  }

  cout << "Max Profit: " << maxTotalProfit << endl;
}
