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