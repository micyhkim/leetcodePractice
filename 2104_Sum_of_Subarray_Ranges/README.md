# 2104. Sum of Subarray Ranges
## Spec
### Problem
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.  
  
Return the sum of all subarray ranges of nums.  
  
A subarray is a contiguous non-empty sequence of elements within an array.  
### Examples
#### Example 1
<pre>
<b>Input</b>: nums = [1,2,3]
<b>Output</b>: 4
<b>Explanation</b>: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
</pre>

#### Example 2
<pre>
<b>Input</b>: nums = [1,3,3]
<b>Output</b>: 4
<b>Explanation</b>: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
</pre>

#### Example 3
<pre>
<b>Input</b>: nums = [4,-2,-3,4,1]
<b>Output</b>: 59
<b>Explanation</b>: The sum of all subarray ranges of nums is 59.
</pre>

### Constraints
* 1 <= nums.length <= 1000
* 1e-9 <= nums[i] <= 1e9

## Solution
### Idea
We need to come up with **O(n)** solution to optimize, and we can achieve using monotomic stack.  
The idea is calculating contribution of each element in the list.  
For example, in the list
<pre>
[2,3,8,7]
We have subarray ranges
    - 2-2 / 3-2 / 8-2 / 7-2
    - 3-3 / 8-3 / 8-3
    - 8-8 / 8-7
    - 7-7
<\pre>