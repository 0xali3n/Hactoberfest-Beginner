import java.util.*;

public class Main
{
    public static String reverseWords(String s) {
      String words[]=s.split("[ ]+");
      StringBuffer k=new StringBuffer("");
      for(int i=words.length-1;i>0;i--)
      {
        if(words[i]!=" ")
        k.append(words[i]+" ");
      }
      if(words[0]!="")
      k.append(words[0]);
      else
        k.delete(k.length()-1,k.length());
      return k.toString();
    }


	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter a sentence");
		String s=sc.nextLine();
		System.out.println("After reversing the sentence is");
		s=reverseWords(s);
		System.out.println(s);
	}
}
