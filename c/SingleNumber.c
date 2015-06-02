/**
 *
 * Given an array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 */
#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main(void)
{
    int nums[9] = {11, 22, 33, 44, 11, 22, 33, 119, 44};
    int single = singleNumber(nums, 9);
    printf("The single number is : %d\n", single);
    return 0;
}

int singleNumber(int* nums, int numsSize)
{
    int single = 0;
    for (int i = 0; i < numsSize; ++i) {
        single ^= nums[i];
    }
    return single;
}
