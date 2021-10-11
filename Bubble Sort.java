import java.util.Scanner; //Importing Scanner Library

public class Program

{

    public static void main(String[] args) {

        

        int [] sort = new int[10];

        int i,j,k,u,v,m;

        

        System.out.println("Enter 10 Numbers : ");

        

        Scanner sc = new Scanner(System.in);

        

        //For loop to accept the input

        for(i = 0; i < (sort.length); i++)

        {

            sort[i] = sc.nextInt();

        }

        

        //Algorithm For Sorting

        for(m = 0; m < 10; m++)

        {

        for(j = 0; j < (sort.length-1); j++)

        {

            /* Swap the values if first value is greater than the second */

            if(sort[j] > sort[j+1])

            {

                v = sort[j];

                u = sort[j+1];

                sort[j] = u;

                sort[j+1] = v;

            }

            

            else

            continue;

          }  

        }

        

        

        //For loop for printing the sorted values

        for(k = 0; k < sort.length; k++)

        {

            System.out.println(sort[k]);

        }

    }

}
