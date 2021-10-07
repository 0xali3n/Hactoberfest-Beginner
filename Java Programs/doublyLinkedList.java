
// Class for Doubly Linked List
public class DLL {
    Node head; // head of list
 
    /* Doubly Linked list Node*/
    class Node {
        int data;
        Node prev;
        Node next;
 
        // Constructor to create a new node
        // next and prev is by default initialized as null
        Node(int d) { data = d; }
    }
 
    // Add a node before the given node
    public void InsertBefore(Node next_node, int new_data)
    {
        /*Check if the given nx_node is NULL*/
        if (next_node == null) {
            System.out.println(
                "The given next node can not be NULL");
            return;
        }
 
        // Allocate node, put in the data
        Node new_node = new Node(new_data);
 
        // Making prev of new node as prev of next node
        new_node.prev = next_node.prev;
 
        // Making prev of next node as new node
        next_node.prev = new_node;
 
        // Making next of new node as next node
        new_node.next = next_node;
 
        // Check if new node is added as head
        if (new_node.prev != null)
            new_node.prev.next = new_node;
        else
            head = new_node;
    }
 
    // Adding a node at the front of the list
    public void push(int new_data)
    {
        /* 1. allocate node
         * 2. put in the data */
        Node new_Node = new Node(new_data);
 
        /* 3. Make next of new node as head and previous as
         * NULL */
        new_Node.next = head;
        new_Node.prev = null;
 
        /* 4. change prev of head node to new node */
        if (head != null)
            head.prev = new_Node;
 
        /* 5. move the head to point to the new node */
        head = new_Node;
    }
 
    // This function prints contents of
    // linked list starting from the given node
    public void printlist(Node node)
    {
        Node last = null;
        System.out.println(
            "Traversal in forward Direction");
        while (node != null) {
            System.out.print(node.data + " ");
            last = node;
            node = node.next;
        }
        System.out.println();
        System.out.println(
            "Traversal in reverse direction");
        while (last != null) {
            System.out.print(last.data + " ");
            last = last.prev;
        }
    }
 
    /* Driver program to test above functions*/
    public static void main(String[] args)
    {
        /* Start with the empty list */
        DLL dll = new DLL();
 
        // Insert 6 at the beginning.
        // So linked list becomes 6->NULL
        dll.push(6);
 
        // Insert  at the beginning.
        // So linked list becomes 7->6->NULL
        dll.push(7);
 
        // Insert 1 at the beginning. So
        // linked list becomes 1->7->6->NULL
        dll.push(1);
 
        // Insert 9 at the beginning.
        // So linked list becomes 9->1->7->6->NULL
        dll.push(9);
 
        // Insert 5, before 7.So linked
        // list becomes 9->1->5->7->6->NULL
        dll.InsertBefore(dll.head.next.next, 5);
 
        System.out.println("Created DLL is: ");
        dll.printlist(dll.head);
    }
}
