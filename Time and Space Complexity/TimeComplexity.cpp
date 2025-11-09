/* What is Time Complexity ?
                             
Time complexity in data structures is a metric that describes how 
long it takes to run an algorithm based on the size of the input data. */

/* to find the time complexity check the number of steps are taken ...

for(i = 0; i < n; i++) {
     cout << "anv" << endl;
}

1) 4 + 3 + 3 + 3 + 3.... 3
3n + 1
Ignore the constant part => n

2) If there is multiple dependencies like 
3N^3 + 2N^2 + N
remove the constant
N^3 + N^2 + N
then the time complexity will be the the largest one N^3
*/

/*1. Big-O (O): Worst-case scenario
Definition: Describes the upper bound of an algorithm's time complexity. It represents the longest time the algorithm could take to complete, regardless of the input.
Example: For a linear search, the worst case happens when the target element is at the last position, resulting in 
𝑂(𝑛)
O(n).
2. Theta (Θ): Average-case scenario
Definition: Describes the tight bound of an algorithm's time complexity. It represents the time the algorithm will take on average, considering all possible inputs.
Example: For a balanced binary search tree, searching an element typically takes 

Θ(logn) on average.
3. Omega (Ω): Best-case scenario
Definition: Describes the lower bound of an algorithm's time complexity. It represents the shortest time the algorithm could take, given the best-case input.
Example: In linear search, the best case occurs when the target element is the first in the list, resulting in 

Ω(1).
Example for Context:
Imagine you're writing about linear search:

Best case (Ω): 

Ω(1) → The target is found at the first position.
Average case (Θ): 

Θ(n/2)=Θ(n) → The target is found roughly in the middle of the list.
Worst case (O): 

O(n) → The target is not found, or it’s at the last position.
Notes for Clarity:
Big-O is the upper bound (guarantee it won't get worse than this).
Theta is the tight bound (typical runtime in the average case).
Omega is the lower bound (fastest runtime possible).*/

/* Example:

for(int i = 1; i <= n; i = i *2) {
     cout << "abc" << endl;
}

i = 1 = 2^0 (abc) || i = 2 = 2^1 (abc) i = 4 = 2^2 (abc)---- i =n = 2^k (abc)
2^2 se pehle 3 baar abc print hue hai 

n = power + 1
we know 2^k  = n
take log both side 
logn = klog2
k = logn/log2
k = log2 n +1
= log2 n */

/*
O(log n) happens when:

Input size reduces by a constant factor in each iteration or recursive call.

Example: Dividing the problem size in half, as in binary search or the updated loop:
cpp
Copy code
for (int i = 1; i <= n; i = i * 2)
Here, i doubles (or the range halves) in each iteration.

Doubling or exponential growth occurs in iterations or data processing.

Example: Each iteration or operation progresses exponentially, like i = i * 2.
Logarithmic growth or reduction dominates in algorithms:

Binary trees: Traversing a balanced binary tree has height proportional to logn
⁡
Recursive algorithms: Divide-and-conquer strategies like merge sort and quicksort splits problems into smaller chunks, often proportional to  logn.
Make sure to note:

The base of the logarithm is usually 2 (but constant differences in base are ignored in Big-O).
O(log n) is typical for highly efficient algorithms that exploit halving or doubling!
*/
/*
1 - 2 - 4 - 8 -16 - 32 ..... => log2n
1-3-9-27-81 .....=> log3n 
*/

/* When the loop is not depend on the one another like then multiply them will give you the time complexity
for(i = n/2; i <= n; i++) { => yeh wala loop chalega n/2 tak
     for(j  1; j<= n/2; j++) {  => yeh wala loop chalega n/2
          for(k = 1; k <= n; k++) => yeh wala loop chalega n tak
               cout << "abc"}
               n/2 * n/2 *n = O(n3)...
     }
}*/

/*
for(int i = n/2; i <= n; i++) {         => n/2
     for(int j = 1; j <= n; j = 2*j){  => double increase ho rha log2n
          for(k = 1; k <= n; k = 2*k); =>  double increase ho rha log2n
     }     
}
          n/2 * log2n *log2n => n/2*(log2n)^2
*/



