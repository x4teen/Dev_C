#include <iostream>
#include <climits>

using namespace std;


int main(int argc, char const *argv[]) {

  // using cin with integer numbers
  int int01, int02;

  std::cout << "Enter two integers : ";
  cin >> int01 >> int02;
  std::cout << int01 << " + " << int02 << " = " << int01+int02 << '\n';

  //use cin with double numbers
  double double01, double02;

  std::cout << "Enter two double numbers : ";
  cin >> double01 >> double02;
  std::cout << double01 << " / " << double02 << " = ";

  if (double02 != 0.0) {
    std::cout << double01 / double02 << "\n";
  } else {
    std::cout << "Error : Division by zero not allowed." << "\n";
  }

  //use cin with sting variables

  string name;

  //Clear the cin buffer to use getline function
  std::cin.clear();
  std::cin.ignore(INT_MAX, '\n');

  std::cout << "Please enter your name : \n";
  // cin >> name;        //only gets the first name
  getline(cin, name);   //gets all strings in the line
  std::cout << "Welcome to C++ Progrmming "<< name << endl;

  cout << "Program completed without error.";    //Delete Test Message After Development
  return 0;
}
