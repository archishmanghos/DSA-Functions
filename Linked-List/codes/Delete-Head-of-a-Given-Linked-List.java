package LinkedList.SinglyLinkedList;

public class Delete_Head_of_a_Given_Linked_List {
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

    public static Node deleteHead(Node head) {
        return head.next;
    }
}