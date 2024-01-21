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