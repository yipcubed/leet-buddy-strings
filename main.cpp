#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/buddy-strings/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  bool buddyStrings(string A, string B) {
    if (A.empty() || B.empty() || A.length() != B.length())
      return false;
    if (A == B) {
      for (char c: A) {
        if (count(A.begin(), A.end(), c) > 1)
          return true;
      }
      return false;
    }
    bool swap_started = false;
    bool swapped = false;
    char swapA, swapB;
    for (int i = 0; i < A.length(); ++i) {
      if (A[i] == B[i])
        continue;
      if (swapped)
        return false;
      if (!swap_started) {
        swapA = A[i];
        swapB = B[i];
        swap_started = true;
      } else {
        if (A[i] != swapB || B[i] != swapA)
          return false;
        swapped = true;
      }
    }
    return swapped;
  }
};

void test1() {
  cout << boolalpha;
  string A = "ab", B = "ba";
  cout << "t ? " << Solution().buddyStrings(A, B) << endl;

  A = "ab", B = "ab";
  cout << "f ? " << Solution().buddyStrings(A, B) << endl;

  A = "aa", B = "aa";
  cout << "t ? " << Solution().buddyStrings(A, B) << endl;

  A = "aaaaaaabc", B = "aaaaaaacb";
  cout << "t ? " << Solution().buddyStrings(A, B) << endl;

  A = "", B = "aa";
  cout << "f ? " << Solution().buddyStrings(A, B) << endl;
}

void test2() {

}

void test3() {

}