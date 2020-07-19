/*
 * https://leetcode-cn.com/problems/next-permutation/
 * 先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
 * 再找出另一个最大索引 l 满足 nums[l] > nums[k]；
 * 交换 nums[l] 和 nums[k]；
 * 最后翻转 nums[k+1:]
 */

void reverse(int *nums, int beg, int end) {
    while (beg < end) {
        int tmp = nums[beg];
        nums[beg] = nums[end];
        nums[end] = tmp;
        beg++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int pos = numsSize;
    
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i-1]) {
            pos = i - 1;
            break;
        }
    }
    
    if (pos == numsSize) {
        reverse(nums, 0, numsSize - 1);
    } else {
        for (int i = numsSize - 1; i > pos; i--) {
            if (nums[i] > nums[pos]) {
                int tmp = nums[i];
                nums[i] = nums[pos];
                nums[pos] = tmp;
                break;
            }
        }
        
        reverse(nums, pos + 1, numsSize - 1);
    }
}
