#include <cmath>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

namespace euler {

bool is_prime(int p, const std::vector<int>& primes) {
  double limit = sqrt(p);
  for (int div : primes) {
    if (div > limit) {
      break;
    }

    if ((p % div) == 0) {
      return false;
    }
  }

  return true;
}

long long sum_primes_below(int n) {
  if (n <= 3) return 2;
  if (n <= 5) return 5;
  if (n <= 7) return 10;

  std::vector<int> primes;
  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);

  long long result = 10;
  int jump = 2;  // Start by 'jumping' from 5 to 7.

  for (int i=7; i<n; i+=jump) {
    if (is_prime(i, primes)) {
      primes.push_back(i);
      result += i;
    }
    jump = 6-jump;
  }

  return result;
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
  long long result = euler::sum_primes_below(n);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << endl << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

