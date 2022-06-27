#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace euler {

int sum_square_diff(int n) {
  long long sum_of_squares = (n*(n+1)*(2*n+1))/6;
  long long square_of_sum = n*n*(n+1)*(n+1)/4;

  return square_of_sum - sum_of_squares;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the top of our natural number range
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int top = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  int result = euler::sum_square_diff(top);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

