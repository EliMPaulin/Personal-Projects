#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>


int checkDirections(int i, int j, std::vector<std::vector<char>> word_search) {

    // std::cout << i << ' ' << j << ' ' << word_search.size() << ' ' << word_search[0].size() << std::endl;
    std::vector<std::string> directions;
    bool N = (i >= 3);
    bool S = (i < (word_search.size() - 3));
    bool W = (j >= 3);
    bool E = (j < (word_search[0].size() - 3));

    // Add directions based on if they're within the bounds of the puzzle.
    if (N) {
        directions.push_back("N");
    }
    if (S) {
        directions.push_back("S");
    }
    if (W) {
        directions.push_back("W");
    }
    if (E) {
        directions.push_back("E");
    }
    if (N && E) {
        directions.push_back("NE");
    }
    if(N && W) {
        directions.push_back("NW");
    }
    if (S && E) {
        directions.push_back("SE");
    }
    if (S && W) {
        directions.push_back("SW");
    }

    int words = 0;

    // Check all valid directions and add 1 if there is a word there
    for (int k = 0; k < directions.size(); k++){

        if (directions[k] == "N") {
            if (word_search[i-1][j] == 'M' && word_search[i-2][j] == 'A' && word_search[i-3][j] == 'S'){
                words++;        
            } 
        } else if (directions[k] == "S") {
            if (word_search[i+1][j] == 'M' && word_search[i+2][j] == 'A' && word_search[i+3][j] == 'S'){
                words++;           
            } 
        } else if (directions[k] == "W") {
            if (word_search[i][j-1] == 'M' && word_search[i][j-2] == 'A' && word_search[i][j-3] == 'S'){
                words++;           
            } 
        } else if (directions[k] == "E") {
            if (word_search[i][j+1] == 'M' && word_search[i][j+2] == 'A' && word_search[i][j+3] == 'S'){
                words++;           
            } 
        } else if (directions[k] == "NE") {
            if (word_search[i-1][j+1] == 'M' && word_search[i-2][j+2] == 'A' && word_search[i-3][j+3] == 'S'){
                words++;           
            } 
        } else if (directions[k] == "NW") {
            if (word_search[i-1][j-1] == 'M' && word_search[i-2][j-2] == 'A' && word_search[i-3][j-3] == 'S'){
                words++;           
            } 
        } else if (directions[k] == "SE") {
            if (word_search[i+1][j+1] == 'M' && word_search[i+2][j+2] == 'A' && word_search[i+3][j+3] == 'S'){
                words++;           
            } 
        } else if (directions[k] == "SW"){
            if (word_search[i+1][j-1] == 'M' && word_search[i+2][j-2] == 'A' && word_search[i+3][j-3] == 'S'){
                words++;           
            } 
        }
    }

    return words;
}

int checkForX(int i, int j, std::vector<std::vector<char>> word_search) {

    

    // Ensure that there is room for an X-MAS around the 'A'
    if ( (i == 0) || (j == 0) || (i == word_search.size() - 1) || (j == word_search[0].size() - 1)) {
        return 0;
    }

    char top_left = word_search[i-1][j-1];
    char top_right = word_search[i-1][j+1];
    char bot_left = word_search[i+1][j-1];
    char bot_right = word_search[i+1][j+1];

    // Ensure the diagonals contain the word "MAS" in the form of an X
    if ( !((top_left == 'M' || top_left == 'S') && (bot_right == 'M' || bot_right == 'S') && (bot_right != top_left)) ){
        return 0;
    }
    if ( !((bot_left == 'M' || bot_left == 'S') && (top_right == 'M' || top_right == 'S') && (top_right != bot_left)) ){
        return 0;
    }

    return 1;

}

void Part1(std::vector<std::vector<char>> word_search) {

    int num_words = 0;

    // Iterate through the puzzle and look for the character 'X'
    for (int i = 0; i < word_search.size(); i++) {
        for (int j = 0; j < word_search[0].size(); j++){

            if (word_search[i][j] != 'X'){
                continue;
            }

            num_words += checkDirections(i, j, word_search);

        }
    }

    std::cout << "\"XMAS\" appears " << num_words << " times." << std::endl;
}

void Part2(std::vector<std::vector<char>> word_search) {

    int num_x = 0;

    // Iterate through the puzzle and look for the character 'A'
    for (int i = 0; i < word_search.size(); i++) {
        for (int j = 0; j < word_search[0].size(); j++){

            if (word_search[i][j] != 'A'){
                continue;
            }

            num_x += checkForX(i, j, word_search);

        }
    }

    std::cout << "\"MAS\" appears in the form of an X " << num_x << " times." << std::endl;

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

    // Store puzzle in 2d vector.
    std::vector<std::vector<char>> word_search; 

    std::string line;

    // Append wordsearch to the 2d vector 
    for (int i = 0; std::getline(input_file, line); i++) {
        std::vector<char> line_vec;

        for (int j = 0; j < line.size(); j++) {
            line_vec.push_back(line[j]);
        }
        word_search.push_back(line_vec);
    }

    Part1(word_search);
    Part2(word_search);

    return 0;
}