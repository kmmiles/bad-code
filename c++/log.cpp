#include <iostream>
#include <cmath>

double mylog(int x, int base) {
  return std::log(x) / std::log(base);
}

int main(void) {
  std::cout << "mylog(2) = " << mylog(256, 2) << std::endl;
  std::cout << "log2 = " << std::log2(256) << std::endl;

  std::cout << "mylog(10) = " << mylog(256, 10) << std::endl;
  std::cout << "log10 = " << log10(256) << std::endl;
}

