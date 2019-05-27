#include <iostream>
#include <stdlib.h>

using namespace std;

#define NOF_COPIES  2

#define PRINT_TYPE_1 << std::string(num - line_n, '-')
#define PRINT_TYPE_2 << std::string(num + line_n * 2 , '*')
#define PRINT_TYPE_3 << std::string(num - line_n * 2, '-')

#define PRINT_TYPE_4 << std::string(num, '*')
#define PRINT_TYPE_5 << std::string(line_n * 2 - num, '-')
#define PRINT_TYPE_6 << std::string((num + (lines_to_print_half - 1) * 2) - ((line_n - lines_to_print_half) * 2), '*')

#define M_PRINT_FIRST_HALF  PRINT_TYPE_1 PRINT_TYPE_2 PRINT_TYPE_3 PRINT_TYPE_2 PRINT_TYPE_1
#define M_PRINT_SECOND_HALF PRINT_TYPE_1 PRINT_TYPE_4 PRINT_TYPE_5 PRINT_TYPE_6 PRINT_TYPE_5 PRINT_TYPE_4 PRINT_TYPE_1 

int main()
{
    int num, copy_n, line_n, lines_to_print, lines_to_print_half;
    std::cout << "Please insert a valid odd number:";

    /*
    * Get the first numeric sequence provided
    */
    while(!(std::cin >> num)) {
       cout << "Value must be numeric.";
       exit (EXIT_FAILURE);
    }

    /*
    * Check if input is odd number
    */
    if (num % 2 == 0) {
       cout << "Value must be an odd number.";
       exit (EXIT_FAILURE);
    }
    
    lines_to_print = num + 1;
    lines_to_print_half = lines_to_print / 2;

	for (line_n = 0; line_n < lines_to_print; line_n++) {
	    if (line_n < lines_to_print_half) {
	        for (copy_n = 0; copy_n < NOF_COPIES; copy_n++) {
	            std::cout M_PRINT_FIRST_HALF;
	        }
            std::cout << std::endl;
        } else {
            for (copy_n = 0; copy_n < NOF_COPIES; copy_n++) {
                std::cout M_PRINT_SECOND_HALF;
            }
            std::cout << std::endl;
	    }
	}

    return 0;
}

