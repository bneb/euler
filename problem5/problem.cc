#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace euler {

int smallest_multiple(int top) {
  int acc = 1;

  vector<int> nums(top);
  for (int i = 0; i < top; i++) {
    nums[i] = i + 1;
  }

  int num;
  for (int ix=1; ix<top; ix++) {
    num = nums[ix];
    if (num == 1) continue;

    acc *= num;

    for (int i=num; i<top; i++) {
      if ((nums[i]%num) != 0) continue;
      nums[i] = nums[i]/num;
    }
  }

  return acc;
}

} // namespace euler

int main (int argc, char *argv[]) {
  // Get the number to bound our loop
  if (argc < 2) {
    cout << "arg required";
    return 1;
  }
  int top = stoi(argv[1]);

  auto start = chrono::high_resolution_clock::now();
  int result = euler::smallest_multiple(top);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::nanoseconds>(stop - start);

  cout << "Result: " << result << endl;
  cout << "  Time: " << dur.count() << " ns" << endl;
  return 0;
}

