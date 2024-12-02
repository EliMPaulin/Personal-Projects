#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <cmath>

int getDifference(int num1, int num2){
    return abs(num1-num2);
}

int main(void) {

    std::ifstream input;

    // Get filename from input.

    std::string filename;
    std::cout << "What is the name of the input file? : ";
    std::cin >> filename;

    input.open(filename);

    // Ensures that the file exists
    assert(input);



    int current_num;
    int counter;
    std::vector<int> list1;
    std::vector<int> list2;

    // The first number in the row is a part of list 1 and the second belongs to list 2.
    for (int counter = 0; !input.eof(); counter++) {
        input >> current_num;

        if (counter % 2 == 0) {
            list1.push_back(current_num);
        } else {
            list2.push_back(current_num);
        }

    }

    // Sort both lists
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int sum = 0;

    for (int i = 0; i < list1.size(); i++) {
        sum += getDifference(list1[i], list2[i]);
    }

    std::cout << "The total distance between the lists is "<< sum << std::endl;

    // Part 2
    int appearances;
    int similarity_sum = 0;

    for (int i = 0; i < list1.size(); i++) {
        int target_val = list1[i];
        appearances = 0;

        // Count the number of appearances of the target value in list2.
        for (int j = 0; list2[j] <= target_val; j++) {

            if (list2[j] == target_val) {
                appearances++;
            } else if (list2[j] > target_val){
                // Exit the loop since the vector is sorted.
                break;
            }
        }
        similarity_sum += (appearances*target_val);
    }

    std::cout << "The similarity score is " << similarity_sum << std::endl;

    return 0;
}
