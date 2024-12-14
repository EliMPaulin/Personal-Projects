#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


/**
 * @param x first value expected in the vector.
 * @param y second value expected in the vector.
 * @param v vector containing both x and y
 * @returns true if x comes before y sequentially in the vector v,
 * or if x or y do not exist in the vetor. Otherwise returns false.
 */
bool isXBeforeY(int x , int y, std::vector<int> v) {

    // Ensure x and y are in v
    bool x_exists = false; 
    bool y_exists = false;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == x) {
            x_exists = true;
        }
        if (v[i] == y){
            y_exists = true;
        }
    }

    // return true since at least one of x or y DNE.
    if (!(y_exists && x_exists)) {
        return true;
    }

    // See which value is encountered first.
    for (int i = 0; i < v.size(); i++){
        if (v[i] == x){
            break;
        } else if (v[i] == y){
            return false;
        }
    }
    // X is before Y
    return true;

}



void Part2(std::vector<std::vector<int>> unordered_updates, std::vector<std::vector<int>> page_ordering_rules) {

    // Put incorrectly ordered updates in the correct order.

    int sum = 0;

    for (int i = 0; i < unordered_updates.size(); i++) {

        for (int j = 0; j < page_ordering_rules.size(); j++){
            if (!isXBeforeY(page_ordering_rules[j][0], page_ordering_rules[j][1], unordered_updates[i])){
                // Swap values in vector

                int index1;
                int index2;

                for (int k = 0; k < unordered_updates[i].size(); k++){
                    if (page_ordering_rules[j][0] == unordered_updates[i][k]){
                        index1 = k;
                    }
                    if (page_ordering_rules[j][1] == unordered_updates[i][k]){
                        index2 = k;
                    }
                }
                
                unordered_updates[i][index1] = page_ordering_rules[j][1];
                unordered_updates[i][index2] = page_ordering_rules[j][0];

                // Check all rules from the beginning with swapped values
                j = -1;
                continue;
            }
        }

        sum += unordered_updates[i][unordered_updates[i].size()/2];

    }
    
    std::cout << "The sum of the middle values of the reorganized updates is: " << sum << "." << std::endl;
}


int main() {
    
    std::string file_name;
    std::cout << "What is the name of the file? : ";
    std::cin >> file_name;

    std::ifstream input_file;
    input_file.open(file_name);

    // Ensure file is open.
    if (!input_file.is_open()) {
        std::cout << "File does not exist or could not open file: " << file_name << std::endl;
        return -1;
    }

    std::vector<std::vector<int>> page_ordering_rules;
     std::string line;

    std::getline(input_file, line);

    // break out of the loop when a line contains "". In the input file the
    // input format changes after an empty line indicated by "".
    while (isdigit(line[0])) {
        std::string str1 = {line[0], line[1]};
        std::string str2 = {line[3], line[4]};
        
        std::vector<int> rules = {stoi(str1), stoi(str2)};

        page_ordering_rules.push_back(rules);

        std::getline(input_file, line);
    }

    std::vector<std::vector<int>> updates;

    // From the input file, append the vector "updates".
    for (int i = 0; std::getline(input_file, line); i++) {

        std::stringstream ss(line);
        std::vector<int> temp;
        std::string token;

        while ( std::getline(ss, token, ',')) {
            temp.push_back(std::stoi(token));
        }

        updates.push_back(temp);

    }


    int sum_of_mid = 0;

    std::vector<std::vector<int>> unordered_updates;

    // Sum the middle values of each update if the update follows the page ordering rules.
    for (int i = 0; i < updates.size(); i++){

        // Test all rules for the specific page.
        for (int j = 0; j < page_ordering_rules.size(); j++) {
            if (!(isXBeforeY(page_ordering_rules[j][0], page_ordering_rules[j][1], updates[i]))){
                
                unordered_updates.push_back(updates[i]);

                // If the page numbers in the update are not in the correct order,
                // goto the end of the loop to avoid summing the middle value.
                goto EOL;
            }
        }

        // Add the middle value of updates[i] to the sum.
        sum_of_mid += updates[i][int(updates[i].size()/2)];

        EOL: ;
    }

    std::cout << "The sum of the middle values of pages is " << sum_of_mid << '.' << std::endl;

    Part2(unordered_updates, page_ordering_rules);

    return 0;
};