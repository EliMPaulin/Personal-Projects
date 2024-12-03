#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>

/// @brief Checks to see if the input contains a don't statement
/// @param input vector of characters.
/// @param i the to start at.
/// @returns true if "don't()" proceeds the given index otherwise false 
bool check_for_dont(std::vector<char> input, int i){

    return (input[i] == ')' && input[i-1] == '(' && input[i-2] == 't' && input[i-3] == '\'' && input[i-4] == 'n' && input[i-5] == 'o' && input[i-6] == 'd');

}

void Part1(std::vector<char> input) {

    int sum_of_mul = 0;

    // Iterate through the input
    for (int i = 7; i < input.size(); i++) {

        if (input[i] == ')' && isdigit(input[i-1])) {

            int num1_size = 1;

            // Check the number of digits
            while (1){
                if (isdigit(input[i-num1_size-1]) && num1_size < 3) {
                    num1_size++;
                    continue;
                } else if (input[i-num1_size-1] == ',') {
                    break;
                } else {
                    // goto to exit embedded while loop
                    goto end_of_loop;
                }
            }

            // Convert num1 to an integer
            std::string num1_str(&input[i-num1_size], &input[i]);
            int num1 = std::stoi(num1_str);

            // If there is no digit after the comma continue
            if (!isdigit(input[i-num1_size-2])){
                continue;
            }

            int num2_size = 1;
            while (1){
                if (isdigit(input[i-num1_size-2-num2_size]) && num2_size < 3) {
                    num2_size++;
                    continue;
                } else if (input[i-num1_size-2-num2_size] == '(') {
                    break;
                } else {
                    goto end_of_loop;
                }
            }

            // Convert num2 to an integer
            std::string num2_str(&input[i-num1_size-1-num2_size], &input[i-1-num1_size]);
            int num2 = std::stoi(num2_str);

            // Ensure that the prefix "mul" exists
            if (input[i-num1_size-num2_size-3] == 'l' && input[i-num1_size-num2_size-4] == 'u' && input[i-num1_size-num2_size-5] == 'm'){
                sum_of_mul += num1 * num2;
            }
        }

        end_of_loop:
    }

    std::cout << "The sum of the multiplications is " << sum_of_mul << '.' << std::endl;

}

void Part2(std::vector<char> input) {

    int sum_of_mul = 0;
    bool okay_to_proceed = !check_for_dont(input, 0);

    for (int i = 7; i < input.size(); i++) {
        
        // If the command "don't()" is encountered
        if (check_for_dont(input, i)){
            okay_to_proceed = false;

        } else 
        // Check if "do()" is encountered
        if (input[i] == ')' && input[i-1] == '(' && input[i-2] == 'o' && input[i-3] == 'd'){
            okay_to_proceed = true;
        }

        // Ensure it is okay to proceed based on "do()" and "don't()" statements.
        if (okay_to_proceed) {

            // Same as Part1() from here
            if (input[i] == ')' && isdigit(input[i-1])) {

                int num1_size = 1;

                while (1){
                    if (isdigit(input[i-num1_size-1]) && num1_size < 3) {
                        num1_size++;
                        continue;
                    } else if (input[i-num1_size-1] == ',') {
                        break;
                    } else {
                        goto end_of_loop;
                    }
                }

                std::string num1_str(&input[i-num1_size], &input[i]);
                int num1 = std::stoi(num1_str);

                if (!isdigit(input[i-num1_size-2])){
                    continue;
                }

                int num2_size = 1;
                while (1){
                    if (isdigit(input[i-num1_size-2-num2_size]) && num2_size < 3) {
                        num2_size++;
                        continue;
                    } else if (input[i-num1_size-2-num2_size] == '(') {
                        break;
                    } else {
                        goto end_of_loop;
                    }
                }

                // Convert num2 to an integer
                std::string num2_str(&input[i-num1_size-1-num2_size], &input[i-1-num1_size]);
                int num2 = std::stoi(num2_str);

                if (input[i-num1_size-num2_size-3] == 'l' && input[i-num1_size-num2_size-4] == 'u' && input[i-num1_size-num2_size-5] == 'm'){
                    sum_of_mul += num1 * num2;
                }
            }

            end_of_loop:
        }
    }
    std::cout << "The sum of the multiplications is " << sum_of_mul << '.' << std::endl;

}


int main() {

// Get the input file name
    std::string filename;
    std::cout << "What is the input file name?: ";
    std::cin >> filename;

    std::ifstream input_file;
    input_file.open(filename);

    //Assert that the file is open
    assert(input_file);


    // Ensure the spaces are included
    input_file >> std::noskipws;

    
    std::vector<char> input;
    char current_char;

    // Append all the characters in the file to a vector.
    while (!input_file.eof()){
        
        input_file >> current_char;
        
        input.push_back(current_char);
    }


    Part1(input);
    Part2(input);

    return 0;
}

