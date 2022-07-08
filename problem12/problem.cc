#include <cmath>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

namespace euler {

int number_of_divisors(long long i) {
  int result = 0;

  for (int di=1; di<=i; di++) {
    if ((i%di) == 0) {
      result++;
    }
  }

  return result;
}

long long first_triangle_with_n_divisors(int n) {
  if (n == 1) {
    return 1;
  }

  long long acc = 1;

  for (int i=2; ; i++) {
    if ((i%10000) == 0) {
      cout << "i: " << i << endl;
    }
    acc+=i;
    if (number_of_divisors(acc) > n) {
      return acc;
    }
  }

  return -1;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the search limit.
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int n = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  long long result = euler::first_triangle_with_n_divisors(n);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << endl << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

