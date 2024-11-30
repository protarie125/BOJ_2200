#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N;
vl C;

ll Log10(ll x) {
  ll ans = 0;
  while (x > 0) {
    x /= 10;
    ++ans;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  C = vl(N + 1);
  for (auto&& c : C) cin >> c;

  ll ans = 2 + (N - 1) * 2;
  ll zeros = 0;
  for (const auto& c : C) {
    if (c == 0) ++zeros;
  }

  ans += N - zeros;

  for (auto i = 1; i < C.size(); ++i) {
    if (C[i] > 0) {
      ans += Log10(C[i]);
    }
  }

  cout << ans;

  return 0;
}