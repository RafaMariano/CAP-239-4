#include <iostream>
#include <math.h>
#include <map>
#include <string>

using namespace std;

int
toDecimal (int num, int base)
{

  int rest = 0;
  int decimal_place = 0;
  int num_in_decimal = 0;

  for (; num > 0; num = num / 10)
    {

      rest = num % 10;

      num_in_decimal = num_in_decimal + (rest * (pow (base, decimal_place)));
      decimal_place++;

    }

  return num_in_decimal;
}


string
toBase_Any (int num, int base_num, int base_return)
{
  map < int, string > ref_hexadecimal = {

    {0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7,
									   "7"},
    {8, "8"},
    {9, "9"}, {10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15,
								      "F"},
  };

  num = toDecimal (num, base_num);
  string num_converted;

  for (; num > 0; num = num / base_return)
    {
      uint rest = num % base_return;
      string temp = ref_hexadecimal.at (rest);
      //    try{
      //       temp = ref_hexadecimal.at(rest);
      //     } catch(...) {
      //       temp = std::to_string(rest);
      //     }
      num_converted = temp + num_converted;
    }

  return num_converted;
}



string
annotation_in_hex (int num, const map < int, string > &ref_hexadecimal)
{

  int rest = 0;
  string hexa_final;

  int cont = 0;

  while (num > 9)
    {

      rest = num % 10;
      num = num / 10;


      if (rest < 6)
	{

	  num = num - 1;
	  hexa_final = ref_hexadecimal.at (rest) + hexa_final;

	}
      else
	{
	  hexa_final = to_string (rest) + hexa_final;
	}
    }

  hexa_final = to_string (num) + hexa_final;
  return hexa_final;

}

string
fraction_toBinary (float num)
{

  double intpart = int (num);
  double floatpart;
  string fractional_binary;
  string part_int_binary = "0";


  if (intpart > 0)
    {
      binary = toBase_Any (intpart, 10, 2);
      num = num - intpart;
    }

  int cont = 0;

  while (num > 0)
    {

      num = num * 2;

      floatpart = modf (num, &intpart);
      fractional_binary = fractional_binary + to_string (int (intpart));

      if (intpart == 1)
        num = num - 1;

    }
  return binary + "." + fractional_binary;
}


int
main ()
{

//  cout << toDecimal (11100, 2);
//  cout << "\n";
//  cout << toBase_Any (59305, 10, 16);

  cout << fraction_toBinary (10.234);


  return 0;
}
