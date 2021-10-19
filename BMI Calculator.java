/*

   Enter like

   80 (weight in kg)

   5.6 (height in ft)

   Female (gender)

   

   or like

   

   90

   5.11

   Male

*/





import java.util.Scanner;

public class Program

{

    public static void main(String[] args) {

        double height, ft, weight, bmi;

            String str = "";

            Scanner scan = new Scanner(System.in);

            weight = scan.nextDouble();

            ft = scan.nextDouble();

            str = scan.next();

            height = ft / 3.28;

            bmi = weight / (double) (Math.pow(height, 2));

            System.out.println("Body Mass Index is " + bmi);

            switch (str){

                case "Female":

                    if (bmi < 19.1){

                        System.out.println("So you are Underweight");

                    }

                    else if (bmi >= 19.1 && bmi <= 25.8){

                        System.out.println("So you have Normal weight");

                    }

                    else if (bmi >= 25.8 && bmi <= 27.3){

                        System.out.println("So you have marginally overweight");

                    }

                    else if (bmi >= 27.3 && bmi <= 32.3){

                        System.out.println("So you have Overweight");

                    }

                    else if (bmi >= 32.3){

                        System.out.println("So you are Obese");

                    }

                    break;

                case "Male":

                    if (bmi < 20.7){

                        System.out.println("So you are Underweight");

                    }

                    else if (bmi >= 20.7 && bmi <= 26.4){

                        System.out.println("So you have Normal weight");

                    }

                    else if (bmi >= 26.4 && bmi <= 27.8){

                        System.out.println("So you have marginally overweight");

                    }

                    else if (bmi >= 27.8 && bmi <= 31.1){

                        System.out.println("So you have Overweight");

                    }

                    else if (bmi >= 31.1){

                        System.out.println("So you are Obese");

                    }

                    break;

            }

    }

}
