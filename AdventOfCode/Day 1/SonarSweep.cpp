#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    size_t increasedCount = 0;
    char buf[128] = {0};
    int prevNum = -1;
    int currNum = -1;
    FILE* input = fopen("input", "r");
    if (!input)
        return -1;

    while(fgets(buf, sizeof(buf), input)){
        currNum = atoll(buf);
        memset(buf, 0 ,sizeof(buf));

        if (prevNum >= 0)
        {
            increasedCount += !!(prevNum <= currNum);
            prevNum = currNum;
        }
        else
        {
            prevNum = currNum;
        }
    }

    cout << "Increased: " << increasedCount << endl;

    fclose(input);
}