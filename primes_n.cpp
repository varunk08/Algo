#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n = 18;
    
    deque<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = true, isPrime[1] = true;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.emplace_back(p);
        }

        for (int i = p; i <= n; i += p) {
            isPrime[i] = false;
        }
    }

    for (auto& i : primes) {
        cout << i << ", ";
    }

    return 0;
}