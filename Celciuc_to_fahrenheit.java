/*   In java Celciuc to Fahrenheit */
import java.util.Scanner;
public class Program {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("enter temp ::: ");
		float celc = scanner.nextFloat();
		float fahren = celc*9/5+32 ;
    System.out.println("in fahrenheit ::: " + fahren);
	}
}
