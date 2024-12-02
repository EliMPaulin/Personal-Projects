#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>
#include <cmath>
#include <vector>

// Ensures the difference between the values is between 1 and 3
bool differenceIsValid(int x, int y) {
    int difference = abs(x-y);
    return ((difference >= 1) && (difference <= 3));
}


bool isReportSafe(std::string report) {


    // Convert to string stream
    std::stringstream sstream(report);

    int previous_val;
    int current_val;

    sstream >> previous_val;
    sstream >> current_val;

    // Used to ensure the the numbers are all increasing or decreasing
    bool convention = (previous_val < current_val);



    if (!differenceIsValid(previous_val, current_val)) {
        return false;
    }

    previous_val = current_val;
    // Iterates through each number in the report
    while (sstream >> current_val) {
        
        if (convention != (previous_val < current_val)) {
            return false;
        }
    

        if (!differenceIsValid(previous_val, current_val)) {
            return false;
        }

        previous_val = current_val;
    }

    return true;
}

// Overloaded function for vectors
bool isReportSafe(std::vector<int> report_vec) {



    int previous_val = report_vec[0];
    int current_val = report_vec[1];


    // Used to ensure the the numbers are all increasing or decreasing
    bool convention = (previous_val < current_val);



    if (!differenceIsValid(previous_val, current_val)) {
        return false;
    }

    previous_val = current_val;
    // Iterates through each number in the report
    for (int i = 2; i < report_vec.size(); i++) {
        current_val = report_vec[i];

        if (convention != (previous_val < current_val)) {
            return false;
        }
    

        if (!differenceIsValid(previous_val, current_val)) {
            return false;
        }

        previous_val = current_val;
    }

    return true;
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

    std::cout << "Should the reports be evaluated using the problem dampener? (Y/N): ";
    char input_char;
    std::cin >> input_char;

    std::string report;

    switch (input_char){
    
    case 'N':{
        int safe_reports = 0;
        while (std::getline(input_file, report)) {
            if (isReportSafe(report)){
                safe_reports++;
            }
            
        }

        std::cout << "There are " << safe_reports << " safe reports." << std::endl;
        break;
    }
    case 'Y':{

        int dampened_safe_reports = 0;

        while (std::getline(input_file, report)) {
            if (isReportSafe(report)){
                dampened_safe_reports++;
            } else {

                // Convert the report to a vector
                std::stringstream report_stream(report);

                int num;
                std::vector<int> report_vec;

                // Append values in string stream to vector
                while (report_stream >> num) {
                    report_vec.push_back(num);
                }
                
                // Try the report with each element removed
                for (int i = 0; i < report_vec.size(); i++){
                    std::vector<int> report_vec_cpy = report_vec;

                    report_vec_cpy.erase(report_vec_cpy.begin() + i);

                    if(isReportSafe(report_vec_cpy)) {
                        dampened_safe_reports++;
                        break;
                    }

                }
            }
            
        }

        std::cout << "Using the problem dampener there are " << dampened_safe_reports << " safe reports." << std::endl;
        break;
        }
    default:
        std::cout << "Invalid input." << std::endl;
    }
    return 0;
}