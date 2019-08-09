#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// 返回值：
// true:  -输入有效，并且数组中存在重复的数字
// false: -输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length, int *duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;

    for(int i=0; i < length; ++i){
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    
    for(int i=0; i < length; ++i){
        while (numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            // 交换numbers[i]和numbers[numbers[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}