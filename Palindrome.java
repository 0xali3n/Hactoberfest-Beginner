import java.util.Scanner;

public class Program

{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String word = sc.nextLine();

        

        String response = Program.buildResponse(word, Program.isPalindrome(word.toLowerCase()));

        

        System.out.println(response);

    }

    

    private static boolean isPalindrome(String word) {

        char[] arr = word.toCharArray();

        

        int length = word.length();

        

        for(int i = 0; i < length / 2; i++) {

            if(arr[i] != arr[length - 1 - i]) {

                return false;

            }

        }

        return true;

    }

    

    private static String buildResponse(String word, boolean isPalindrome) {

        String result = isPalindrome ? "is palindrome." : "is not palindrome.";

        String response = "\"" + word + "\"" + " " + result;

        return response;

    }

}
