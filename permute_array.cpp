#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> perm = { 2, 0 , 1, 3};
    vector<char> A = {'a', 'b', 'c', 'd'};
    for_each(begin(A), end(A), [&A](char& c) {cout << c << ",";});

    for (int i = 0; i < size(A); i++) {
        int next = i;

        while (perm[next] >= 0) {
            swap(A[i], A[perm[next]]);
            int temp = perm[next];
            perm[next] -= size(perm);

            next = temp;
        }
    }
    cout << endl;
    for_each(begin(A), end(A), [&A](char& c) {cout << c << ","; });
    return 0;
}