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