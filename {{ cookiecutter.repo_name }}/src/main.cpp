#include <iostream>
#include <torch/torch.h>
#include "calculator.hpp"

int main() {

  metal::Calculator c;

  std::cout << "3 + 4 = " << c.add(3, 4) << std::endl;

}
