import java.util.Scanner;
public class BinaryAddition {
   public static void main(String[] args)
   {
       Scanner in = new Scanner(System.in);
       int t = in.nextInt();
       while(t!=0)
       {
           helperfunction(in);
           t = in.nextInt();
       }
   }
   public static void helperfunction(Scanner in)
   {	 
	long bin1, bin2;
	int i = 0, carry = 0;
	int[] sum = new int[10];
	System.out.print("Enter first binary number: ");
	bin1 = in.nextLong();
	System.out.print("Enter second binary number: ");
	bin2 = in.nextLong();
	while (bin1 != 0 || bin2 != 0) 
	{
		sum[i++] = (int)((bin1 % 10 + bin2 % 10 + carry) % 2);
		carry = (int)((bin1 % 10 + bin2 % 10 + carry) / 2);
		bin1 = bin1 / 10;
		bin2 = bin2 / 10;
	}
	if (carry != 0) {
		sum[i++] = carry;
	}
	--i;
	System.out.print("Output: ");
	while (i >= 0) {
		System.out.print(sum[i--]);
	}
	System.out.print("\n");  
   }
}