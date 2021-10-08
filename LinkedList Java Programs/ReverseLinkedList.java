import java.util.*;
class Node {
    int data;
    Node next;
    Node(int d)
    {
        next = null;
        data = d;
    }
}
class ReverseLinkedList 
{
	public static void main(String[] args) 
	{
		Node one = new Node(1);
        Node two = new Node(2);
        Node three = new Node(7);
        Node four = new Node(4);
        Node five = new Node(5);
        one.next = two;
        two.next = three;
        three.next = four;
        four.next = five;
		System.out.println("Printing list before reversing::");
		print(one);
		//reversing
		Node rev = reverse(one);
		System.out.println("Printing list after reversing::");
		print(rev);
	}
	static void print(Node head){
		while(head!=null){
			System.out.print(head.data+" ");
			head = head.next;
		}
		System.out.println();
	}
	static Node reverse(Node head)
    {
        // code here
        Node prev = null;
        Node curr = head;
        while(curr!=null){
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}
