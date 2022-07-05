#include <cmath>
#include <chrono>
#include <iostream>
#include <stdlib.h>

using namespace std;

namespace euler {

// Find a*b*c for a pythagorean triple where elements sum to sum.
int find_pythagorean_triple(int sum) {
  /**
   *  a*a + b*b = c*c
   *  a+b+c = sum
   *  a<b<c
   */
  for (int a = sum/3; a>0; a--) {
    for (int b=a+1; b<sum-1; b++) {
      int c = sum-a-b;
      if (c*c == a*a + b*b) {
        return a*b*c;
      }
    }
  }
  return -1;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number of adjacent digits required
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int n = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  long result = euler::find_pythagorean_triple(n);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << endl << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

