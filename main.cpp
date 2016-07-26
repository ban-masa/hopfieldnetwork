#include "lib.h"
#include "HFN.hpp"

void print_ar1(std::array<int, size> ar)
{
  for (int i = 0; i < sizey; i++) {
    for (int j = 0; j < sizex; j++) {
      std::cout << ar.at(i * sizey + j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void print_ar2(std::array<int, size> ar)
{
  for (int i = 0; i < sizey; i++) {
    for (int j = 0; j < sizex; j++) {
      if (ar.at(i * sizey + j) == 1) {
        std::cout << 'o';
      } else {
        std::cout << 'x';
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main(void)
{
  HFN hfn;
  hfn.read_data("data1.txt");
  hfn.read_data("data2.txt");
  hfn.read_data("data3.txt");
  hfn.study();

  std::array<int, size> ans1 = hfn.test("test1.txt");
  std::array<int, size> ans2 = hfn.test("test2.txt");
  std::array<int, size> ans3 = hfn.test("test3.txt");

  print_ar2(ans1);
  print_ar2(ans2);
  print_ar2(ans3);
  
  return 0;
}
