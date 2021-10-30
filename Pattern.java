public class Program

{

    public static void main(String[] args) {

        

        int i = 1;

        char c = 'a';

        String s = "=";

        

        while(i < 10){

            

            switch(i % 2){

                

                case 0:

                   

                    int j = 0;

                 

                     while(j < i){

                     

                         System.out.print(c);

                         j++;

                     }

                 

                     System.out.println();

                     c++;

                     break;

                 

                 case 1: 

                    

                     System.out.println(s);

                     s += "==";

                     break;

                 

            }

            

            i++;

        }

    }

}
