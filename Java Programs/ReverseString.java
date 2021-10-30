import java.util.*;
import java.io.*;
class ReverseString
{
    public static String reverse(String str) 
    {
            char[] charArr = str.toCharArray();
            int size = charArr.length;
            Stack stack = new Stack();
    
            int i;
            for(i = 0; i < size; ++i) {
                stack.push(charArr[i]);
            }
    
            for(i = 0; i < size; ++i) {
                charArr[i] = (char)stack.pop();
            }
    
            return String.valueOf(charArr);
    }
    public static void main (String args[])
    {
        Scanner in = new Scanner (System.in);
        System.out.println("Enter the string:");
        String s = in.nextLine();
        System.out.println("Reversed String: "+ reverse(s));
    }
        
}
