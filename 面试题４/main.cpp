#include <iostream>
#include <cstdio>

bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            if(matrix[row * columns + column] == number)
            {
                found = true;
                break;
            } else if(matrix[row * columns + column] > number)
                --column;
            else
                ++row;
        }
    }
    return found;
}

// 测试代码
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    bool result = Find(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed. \n");
    else
        printf("Failed. \n");
}

void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}


int main(int argc, char* argv[])
{
    Test1();
    return 0;
}





















