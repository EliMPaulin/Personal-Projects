#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::vector<int>> getGuardPosition(std::vector<std::string> lab_map) {

    std::vector<std::vector<int>> guard_telemetry;

    for (int y = 0; y < lab_map.size(); y++) {
        for (int x = 0; x < lab_map[y].size(); x++){
            std::vector<int> position = {x, y};
            if (lab_map[y][x] == '^'){

                std::vector<int> direction = {1, 1};
                guard_telemetry = {direction, position};
                return guard_telemetry;
                
            } else if (lab_map[y][x] == 'v') {

                std::vector<int> direction = {0, 0};
                guard_telemetry = {direction, position};
                return guard_telemetry;

            } else if (lab_map[y][x] == '<') {

                std::vector<int> direction = {1, 0};
                guard_telemetry = {direction, position};
                return guard_telemetry;
                
            } else if (lab_map[y][x] == '>') {

                std::vector<int> direction = {0, 1};
                guard_telemetry = {direction, position};
                return guard_telemetry;

            }
        }
    }


}


int main() {

    std::string file_name;
    std::cout << "Enter the name of the input file: ";
    std::cin >> file_name;



    std::ifstream input_file;
    input_file.open(file_name);

    if (!(input_file.is_open())) {

        std::cout << "Could not find file with name \"" << file_name << "\"" << std::endl;

        return -1;
    }

    std::vector<std::string> lab_map;
    std::string line;

    // Append lab map with puzzle input.
    while (std::getline(input_file, line)) {
        lab_map.push_back(line);
    }





    return 0;
}