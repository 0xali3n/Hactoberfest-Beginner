import java.util.Scanner;
import java.util.Arrays;
public class SieveOptimised {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        boolean arr[]=new boolean[n+1];
        for(int i=0;i<n+1;i++){
            arr[i]=true;
        }
        for(int j=2;j<=n;j++){
            if(arr[j]==true){
                //if true then print
                //if not then already false
                System.out.println(j);
                //then go and eliminate all multiples of j in the array
                for(int i=j*j;i<=n;i+=j){
                    arr[i]=false;
                }
            }
        }
        
        
        

    }
}