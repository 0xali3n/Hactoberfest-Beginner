import java.util.*;

public class calculations{
public static void main(String args[]){

  int a;
  int b;
  char c;
  Scanner sc  = new Scanner (System.in);
  System.out.println("Enter the value of a");
  a = sc.nextInt();
  
  System.out.println("Enter the value of b");
  b = sc.nextInt();
  
  System.out.println(" Select the operation you want to perform" + " '+', '-' ,'*' ,'/' ,'%' ");
  
  c = sc.next().CharAt(0);
  
  switch (c)
  {
    case "+" :System.out.println("The sum of  a and b is " + (a+b));
      break;
      
    case "- " : System.out .println("The subtraction of a and b is " + (a-b));
      break;
    
      
    case "*" : System.out.println("The multiplication of a and b is " + (a*b));
      break;
      
    case "/" :System.out.println("The division of a and b is " + (a/b));
      break;
      
    case "%": System.out.println("The modulo of a and b is " + (a%b));
      break;
      
      default : System.out.println("Invalid choice");
  }
  
  
  
  
  
  
 }
  
}
