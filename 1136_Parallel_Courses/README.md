# Parallel Courses
## Category
Breadth First Search
## Explanation
At each semester, we want to take as many courses that are possible. What is the condition of "possible courses?".
The answer is that when there are no classes (graph nodes) pointing to the class. We create data structure that ecnompasses
courses for each semester and iterate over the courses to let the next course (courses that have current course as prerequisite)
know that this course is taken. Then we check courses that must be taken after this course and push that to the next semster queue.
Then we do the same thing for next semester's queue.  
  
The validation is done when all of the courses are taken (i.e. all of the courses have innode zero).

## Algorithm
* We iterate through course schedule and create graph mapping prerequisite to the courses that must be taken after && how many prerequisites must be taken before taking the current node
* We iterate through the inNode, and push the classes with 0 prerequisites to the queue
* Perform search algorithm: Iterate through the classes in queue and decrement the prerequisite numer for courses that current course is pointing to.
* We push the courses that have prerequisite number 0 after decrementing to the next semester queue.
* Validate by checking if all courses are taken by checking all courses have 0 inNodes