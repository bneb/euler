#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

namespace euler {

int problem2(int upper_bound) {
  int lef = 1;
  int rig = 2;
  int acc = 0;
  int tmp = 0;

  while (rig < upper_bound) {
    if ((rig&1) == 0) {
      acc += rig;
    }
    tmp = lef+rig;
    lef = rig;
    rig = tmp;
  }

  return acc;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number to bound our loop
  if (argc < 2) {
    cout << "upper bound required as arg";
    return 1;
  }
  int upper_bound = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  int result = euler::problem2(upper_bound);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::microseconds>(stop - start);
  cout << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " μs" << endl;
  return 0;
}

