# 84. Largest Rectangle in Histogram
## Category
Monotonic Stack
## Intuition
The calculation of area is done by height * width. Height is the minimum bar. If we maintain strictly increasing stack,
by popping all previous bars taller than the current one, it is guaranteed that the each bar will be the minimum until the previous
position. As we are popping, we calculate the area. The height is height of the top index, and the width is the index at the top of the stack - index at the next top of the stack(until the next small). We remember the max area. After popping, we push the current idx to the stack for future calculation.  
We have to do the samething at the end of the iteration since there must be some left over bars by not encountering any shorter bar as we iterate
## Algorithm
* Iterate through the heights
* While st.top is not empty(or st.top = -1 for placeholder) and height of st.top is greater than the current one to maintain monotonically increasing stack, we pop the idx in stack
* As we pop, we calculate the area. Height is height of the st.top idx and width is the st.top idx and the next st.top (the next short bar)
* After iteration, we do the same popping and calculatio until the stack is empty(or st.top = -1), to consider all bars.

## Analysis
* Time complexity **O(n)**
* Space complexity **O(n)**