#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

namespace euler {

int problem1(int upper_bound) {
  int acc = 0;

  vector<int> jump_increments = {2, 1, 3, 1, 2, 3, 3};
  int n_jump_increments = jump_increments.size();
  int jump_index=0;

  int i = 3;

  while (i < upper_bound) {
    acc += i;
    i += jump_increments[jump_index++];
    if (jump_index >= n_jump_increments) {
      jump_index = 0;
    }
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
  int result = euler::problem1(upper_bound);
  auto stop = chrono::high_resolution_clock::now();
  auto dur = duration_cast<chrono::microseconds>(stop - start);
  cout << "Accumulated value: " << result << endl;
  cout << "             Time: " << dur.count() << " μs" << endl;
  return 0;
}

