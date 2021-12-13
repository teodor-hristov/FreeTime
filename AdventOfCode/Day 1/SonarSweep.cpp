#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

static size_t getIncreasingFromFile(const char *const inputFile) {
    size_t increasedCount = 0;
    char buf[128] = {0};
    int prevNum = -1;
    int currNum = -1;
    FILE *input = fopen(inputFile, "r");
    if (!input)
        return -1;

    while (fgets(buf, sizeof(buf), input)) {
        currNum = atoll(buf);
        memset(buf, 0, sizeof(buf));

        if (prevNum >= 0) {
            increasedCount += !!(prevNum < currNum);
            prevNum = currNum;
        } else {
            prevNum = currNum;
        }
    }

    fclose(input);
    return increasedCount;
}

static void generateNewInputFile(const char *const inputFile, const char *const newInputFile) {
    char buf[128] = {0};
    int numbers[3] = {0};
    FILE *output = fopen(newInputFile, "w+");
    FILE *input = fopen(inputFile, "r");
    if (!input || !output) {
        if (input) fclose(input);
        if (output) fclose(output);
        return;
    }

    fseek(output, 0, SEEK_SET);
    fseek(input, 0, SEEK_SET);

    size_t currNum = 0;
    size_t t = 0;
    bool firstStep = false;
    while (fgets(buf, sizeof(buf), input)) {
        currNum = atoll(buf);
        memset(buf, 0, sizeof(buf));

        if (t == 2 && a)
        {
            swap(numbers[0], numbers[1]);
            swap(numbers[1], numbers[2]);
        }

        numbers[t] = currNum;

        if (t < 2){
            t++;
            continue;
        }

        sprintf(buf, "%d\n", numbers[0] + numbers[1] + numbers[2]);
        fputs(buf, output);
        memset(buf, 0, sizeof(buf));
        firstStep = true;
    }

    fclose(input);
    fclose(output);
};

int main() {
    generateNewInputFile("input", "input2");
    cout << "Increased: " << getIncreasingFromFile("input2") << endl;
}