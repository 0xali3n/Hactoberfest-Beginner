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
class PalindromeLinkedList{
    public static void main(String args[])
    {
        Node one = new Node(1);
        Node two = new Node(2);
        Node three = new Node(3);
        Node four = new Node(2);
        Node five = new Node(1);
        one.next = two;
        two.next = three;
        three.next = four;
        four.next = five;
        boolean condition = isPalindrome(one);
        System.out.println("isPalidrome :" + condition);
    }
    static boolean isPalindrome(Node head)
    {
		String s = "";
        while(head!=null){
            s = s + String.valueOf(head.data);
            head = head.next;
        }
        StringBuilder sb = new StringBuilder(s);
        String rev = sb.reverse().toString();
        if(s.equals(rev)){
            return true;
        }
        return false;
    }
}
 
