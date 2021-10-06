import java.util.*;

class Node{
	int data;
	Node next;
	Node( int data){
		this.data=data;
		this.next=null;
	}
}

public class InsertBegin
{
	public static void main (String []args) 
    {
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter no. of elemets");
		int n=sc.nextInt();

		System.out.println("Enetr elements");
		Node head1=new Node(sc.nextInt());
		Node head=head1;

		for(int i=0;i<n-1;i++)
		{
			Node ptr=new Node(sc.nextInt());
			head1.next=ptr;
			head1=head1.next;
		}
        
		System.out.println("Enter element to be added at the begining");
		int value=sc.nextInt();
		Node ptr=new Node(value);
		ptr.next=head;
		while(ptr!=null)
		{
			System.out.print(ptr.data+" ");
			ptr=ptr.next;
		}
	}
}