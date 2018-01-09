#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string msg = "Hello, World";
  std::cout <<"cout: "<< msg << "\tsize: "<< sizeof(msg) << '\n';

  return 0;
}
