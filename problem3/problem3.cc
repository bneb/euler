#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace euler {

long long greatest_prime_factor(long long n) {
  while ((n%2) == 0) {
    n /= 2;
  }
  if (n == 1) {
    return 2;
  }

  while ((n%3) == 0) {
    n /= 3;
  }
  if (n == 1) {
    return 3;
  }

  int jump = 2;
  long long div = 5;

  while (div < sqrt(n) && n > 1) {
    while((n%div) == 0) {
      n /= div;
    }

    div += jump;
    jump = 6-jump;
  }
  if (n == 1) {
    return div;
  }

  return n;
}

bool is_prime(int n) {
  if ((n&1) == 0 || (n%3) == 0) {
    return false;
  }

  int jump = 2;
  int div = 5;

  while (div < sqrt(n)) {
    if ((n%div) == 0) {
      return false;
    }
    div += jump;
    jump = 6-jump;
  }
  return true;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number to bound our loop
  if (argc < 2) {
    cout << "upper bound required as arg";
    return 1;
  }
  long long upper_bound = stoll(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  long long result = euler::greatest_prime_factor(upper_bound);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);
  cout << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

