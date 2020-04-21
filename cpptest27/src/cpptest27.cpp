//============================================================================
// Name        : cpptest27.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Exception in C++
//============================================================================

#include <iostream>

struct GeneralException {
  virtual void print() { std::cout << "G"; }
};

struct SpecialException : public GeneralException {
  void print() override { std::cout << "S"; }
};

void f() { throw SpecialException(); }

int main() {
  try {
    f();
  }
  catch (GeneralException e) {	//caught by value, (GeneralException& e) caught by reference
    e.print();
  }
}
