/*
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        
        for (int i = 0; i < k; i++) {
            heap.push_back(nums[i]);
        }
        
        // build heap
        for (int i = 1; i < k; i++) {
            int j = i;
            while(j > 0 && heap[j] < heap[(j+1)/2 - 1]) {
                int tmp = heap[j];
                heap[j] = heap[(j+1)/2 - 1];
                heap[(j+1)/2 - 1] = tmp;
                j = (j+1)/2 - 1;
            }
        }
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                // heapify
                int p = 0;
                while(true) {
                    int left = (p + 1) * 2 - 1;
                    int right = (p + 1) * 2;
                    
                    if (left > k - 1) {
                        break;
                    } else if (right > k - 1) {
                        if (heap[left] < heap[p]) {
                            int tmp = heap[p];
                            heap[p] = heap[left];
                            heap[left] = tmp;
                        }
                        break;
                    } else {
                        if (heap[left] <= heap[right] && heap[left] < heap[p]) {
                            int tmp = heap[p];
                            heap[p] = heap[left];
                            heap[left] = tmp;
                            p = left;
                        } else if (heap[left] > heap[right] && heap[right] < heap[p]) {
                            int tmp = heap[p];
                            heap[p] = heap[right];
                            heap[right] = tmp;
                            p = right;
                        } else {
                            break;
                        }
                    }
                }
                
            }
        }
        
        return heap[0];
    }
};
