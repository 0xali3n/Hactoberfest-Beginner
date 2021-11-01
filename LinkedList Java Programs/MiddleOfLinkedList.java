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
class MiddleOfLinkedList 
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
		System.out.println("Middle element of linked List :" +getMiddle(one));
		//output will be 7
	}
	static int getMiddle(Node head)
    {
         Node slow = head;
         Node fast = head;
         while(fast!=null && fast.next!=null){
             fast = fast.next.next;
             slow = slow.next;
         }
         return slow.data;
    }
}
