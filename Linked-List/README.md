### Please try to solve the problems first before seeing the solution. This repository contains clean codes. Enjoy!

<div align="center" id="top">
	<h3>Click on the Lecture you want to go!</h3>
   <table>
      <thead>
         <tr>
            <th align="left"></th>
            <th align="left"></th>
            <th align="left"></th>
            <th align="left"></th>
            <th align="left"></th>
            <th align="left"></th>
            <th align="left"></th>
            <th align="left"></th>
         </tr>
      </thead>
      <tbody>
         <tr>
            <td align="left"><a href="#1">Lecture-1</a></td>
            <td align="left"><a href="#2">Lecture-2</a></td>
            <td align="left"><a href="#3">Lecture-3</a></td>
            <td align="left"><a href="#4">Lecture-4</a></td>
            <td align="left"><a href="#5">Lecture-5</a></td>
            <td align="left"><a href="#6">Lecture-6</a></td>
            <td align="left"><a href="#7">Lecture-7</a></td>
            <td align="left"><a href="#8">Lecture-8</a></td>
         </tr>
      </tbody>
   </table>
</div>

<br>

<h4 id="1">Lecture 1</h4>

1. [Lec-1  Introduction To Linked List [Code Studio]](https://www.codingninjas.com/studio/problems/introduction-to-linked-list_8144737)

```java
package LinkedList.SinglyLinkedList;

public class Introduction_To_Linked_List {
    static class Node {
        public int data;
        public Node next;

        Node() {
            this.data = 0;
            this.next = null;
        }

        Node(int data) {
            this.data = data;
            this.next = null;
        }

        Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    public static Node constructLL(int[] arr) {
        Node head = new Node(arr[0]);
        Node pre = head;

        for (int i = 1; i < arr.length; i++) {
            pre.next = new Node(arr[i]);
            pre = pre.next;
        }

        return head;
    }
}
```

<br>

<h4 id="2">Lecture 2</h4>

2. [Lec-2  Count nodes of linked list [Code Studio]](https://www.codingninjas.com/studio/problems/count-nodes-of-linked-list_5884)

```java
package LinkedList.SinglyLinkedList;

public class Count_nodes_of_linked_list {
    static class Node {
        public int data;
        public Node next;

        Node() {
            this.data = 0;
            this.next = null;
        }

        Node(int data) {
            this.data = data;
            this.next = null;
        }

        Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    public static int length(Node head) {
        int answer = 0;
        while (head != null) {
            answer++;
            head = head.next;
        }

        return answer;
    }
}
```

<br>

<h4 id="3">Lecture 3</h4>

3. [Lec-3  Search in a Linked List [Code Studio]](https://www.codingninjas.com/studio/problems/search-in-a-linked-list_975381)

```java
package LinkedList.SinglyLinkedList;

public class Search_in_a_Linked_List {
    static class Node {
        public int data;
        public Node next;

        Node() {
            this.data = 0;
            this.next = null;
        }

        Node(int data) {
            this.data = data;
            this.next = null;
        }

        Node(int data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    public static int searchInLinkedList(Node head, int k) {
        while (head != null) {
            if (head.data == k) return 1;
            head = head.next;
        }

        return 0;
    }
}
```

<br>