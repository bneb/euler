#include <chrono>
#include <cmath>
#include <iostream>

using namespace std;

namespace euler {

bool is_prime(int n) {
  if ((n&1) == 0 || (n%3) == 0) {
    return false;
  }

  int jump = 2;
  int div = 5;

  while (div <= sqrt(n)) {
    if ((n%div) == 0) {
      return false;
    }
    div += jump;
    jump = 6-jump;
  }
  return true;
}

int find_nth_prime(int n) {
  if (n == 1) return 2;
  if (n == 2) return 3;

  int i = 4;
  while (n-2 > 0) {
    if (is_prime(++i)) {
      n--;
    }
  }

  return i;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number of the prime to be found
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int n = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  int result = euler::find_nth_prime(n);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

