#include <iostream>
#include <cstring>

using namespace std;

const char* const fileName = "input";

typedef struct position{
    int horizontal;
    int vertical;
    int aim;
}Position_t;

Position_t calculatePosition_Part1(const char* const inputFileName){
    char buf[255] = {0,};
    char movement[32] = {0,};
    int movementSteps = 0;
    Position_t position = {0,0,0};
    FILE* fp = fopen(fileName, "r");
    if(!fp) return {-1,-1};

    while(fgets(buf, sizeof(buf), fp)){       
        sscanf(buf, "%s %d", movement, &movementSteps);
        if (strstr(movement, "up") != nullptr) 
        {
            position.vertical -= movementSteps;
        }
        if (strstr(movement, "down") != nullptr) 
        {
            position.vertical += movementSteps;
        }
        if (strstr(movement, "forward") != nullptr) 
        {
            position.horizontal += movementSteps;
            position.vertical += movementSteps*position.aim;
        }


        printf("aim: %d horizontal: %d vertical: %d\n", position.aim,
        position.horizontal, position.vertical);
   }

    return position;
}

Position_t calculatePosition_Part2(const char* const inputFileName){
    char buf[255] = {0,};
    char movement[32] = {0,};
    int movementSteps = 0;
    Position_t position = {0,0,0};
    FILE* fp = fopen(fileName, "r");
    if(!fp) return {-1,-1};

    while(fgets(buf, sizeof(buf), fp)){       
        sscanf(buf, "%s %d", movement, &movementSteps);
        if (strstr(movement, "up") != nullptr) 
        {
            position.aim -= movementSteps;
        }
        if (strstr(movement, "down") != nullptr) 
        {
            position.aim += movementSteps;
        }
        if (strstr(movement, "forward") != nullptr) 
        {
            position.horizontal += movementSteps;
            position.vertical += movementSteps*position.aim;
        }
   }

    return position;
}

int main(){
    Position_t pos1 = calculatePosition_Part1(fileName);
    cout << "Part 1: " << pos1.horizontal * pos1.vertical << endl;

    Position_t pos2 = calculatePosition_Part2(fileName);
    cout << "Part 2: " << pos2.horizontal * pos2.vertical << endl;

}