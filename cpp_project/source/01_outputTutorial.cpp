#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
using namespace std;


int main(int argc, char const *argv[]) {
  //monthly Reading Data
  double month_01, month_02, month_03, month_04;
  month_01 = 1061.2363;
  month_02 = 1073.47;
  month_03 = 1071.6378;
  month_04 = 1069.736;

  //Print the Data
  std::cout << setprecision(10);
  std::cout << "Month\t" << "Reading \n";
  std::cout << 1 << "\t"<< month_01<<"\n";
  std::cout << 2 << "\t"<< month_02<<"\n";
  std::cout << 3 << "\t"<< month_03<<"\n";
  std::cout << 4 << "\t"<< month_04<<"\n";


  //Print the data in formatted table
  int fieldLength = 15;
  //write the table header
  std::cout << setw(10) << "Month" << setw(fieldLength) << "Reading" << "\n";
  std::cout << setw(10) << 1 << setw(fieldLength) << month_01 << "\n";
  std::cout << setw(10) << 2 << setw(fieldLength) << month_02 << "\n";
  std::cout << setw(10) << 3 << setw(fieldLength) << month_03 << "\n";
  std::cout << setw(10) << 4 << setw(fieldLength) << month_04 << "\n";

  //Print a message about the number pi
  double pi = 355.0/113.0;
  string discoveredBy = "Archimedes";
  int yearsAgo = 4000;

  printf("The number pi was discovered %d years ago.\n", yearsAgo);
  printf("%s calculeted pi\'s value to be %.20f \n", discoveredBy.c_str(), pi);


  cout << "Program completed without error.";    //Delete Test Message After Development
  return 0;
}
