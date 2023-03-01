Build a max heap with the given array. <br>
This can be done by calling heapify() for all the leaf nodes.<br>
The leaf nodes are from A[(n / 2)] to A[n - 1] (0-indexed) or A[(n / 2) + 1] to A[n] (1-indexed).<br>
Next, for every element from N - 1 to 0, heapify and swap the 1st element with the ith element (where i is N - 1 to 0).<br>
Decrease N by 1 in each step.<br>

<details><summary>Clean Code</summary>

![](../../assets/heap-sort.png)

</details>
