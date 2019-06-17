// C++17 implemention of 1062c.py

#include <iostream>

long long int mod = 1000000007;

int main(){
  int n, q;
  std::cin >> n >> q;
  char x[100000];
  std::cin >> x;
  long long int sum_list[100001];
  sum_list[0] = 0;
  for (int i = 1; i <= n; i++){
    sum_list[i] = sum_list[i - 1] + (x[i - 1] - '0');
  }
  long long int enjoyment_list[100001];
  enjoyment_list[0] = 0;
  for (int i = 1; i <= 100000; i++){
    enjoyment_list[i] = (enjoyment_list[i - 1] * 2 + 1) % mod;
  }
  for (int i = 0; i < q; i++){
    int l, r;
    std::cin >> l >> r;
    int banhmi_count = r - l + 1;
    int delicious_count = sum_list[r] - sum_list[l - 1];
    int non_delicious_count = banhmi_count - delicious_count;
    int enjoyment = 0;
    // main part
    if (delicious_count == 0){
      enjoyment = 0;
    } else {
      //enjoyment += enjoyment_list[delicious_count];
      //enjoyment += enjoyment_list[banhmi_count] - enjoyment_list[delicious_count] - enjoyment_list[non_delicious_count];
      //enjoyment = enjoyment % mod;
      // Positive modulo: (x % mod + mod) % mod
      enjoyment = ((enjoyment_list[banhmi_count] - enjoyment_list[non_delicious_count]) % mod + mod) % mod;
    }
    std::cout << enjoyment << std::endl;
  }
  return 0;
}
