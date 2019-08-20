#include <iostream>
#include <cstring>

void ReplaceBlank(char string[], int length)
{
    if(string == nullptr && length <= 0)
        return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        ++originalLength;
        if(string[i] == ' ')
            ++numberOfBlank;
        ++i;
    }

    int newLength = originalLength + 2 * numberOfBlank;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        } else{
            string[indexOfNew--] = string[indexOfOriginal];
        }

        --indexOfOriginal;
    }
}

// 测试代码
void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("failed.\n");
    else if(expected == nullptr & str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed,\n");
}

// 测试demo 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

int main()
{
    Test1();

    return 0;
}








