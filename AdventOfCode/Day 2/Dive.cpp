#include <iostream>
#include <cstring>

using namespace std;

const char* const fileName = "input";

typedef struct position{
    int horizontal;
    int vertical;
}Position_t;

Position_t calculatePosition(const char* const inputFileName){
    char buf[255] = {0,};
    char movement[32] = {0,};
    int movementSteps = 0;
    Position_t position = {0,0};
    FILE* fp = fopen(fileName, "r");
    if(!fp) return {-1,-1};

    while(fgets(buf, sizeof(buf), fp)){
        sscanf(buf, "%s %d", movement, &movementSteps);
        if (strstr(movement, "up") != nullptr) {position.horizontal -= movementSteps;}
        if (strstr(movement, "down") != nullptr) {position.horizontal += movementSteps;}
        if (strstr(movement, "forward") != nullptr) {position.vertical += movementSteps;}
    }

    return position;
}

int main(){
    Position_t pos = calculatePosition(fileName);
    cout << pos.horizontal * pos.vertical << endl;

}