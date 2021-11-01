import java.util.*;
public class Main
{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter th customer name");
        String name = sc.nextLine();
        System.out.println("Enter the category");
        String category=sc.nextLine();
        int gram;
        float disc=0;
        if(category.equals("TempleJewelry")){
            System.out.println("Enter the grams of gold purchased");
            gram = sc.nextInt();
            if (gram <= 0){
                System.out.println(gram +" is an invalid quantity");
                return;
            }
            if(gram>=20) 
            disc = 15;
            
        }
        else if(category.equals("KundanJewelry")){
            System.out.println("Enter the grams of gold purchased");
            gram = sc.nextInt();
            if(gram<=0){
            System.out.println(gram + " is an invalid quantity");
            return;
        }
        if(gram >= 25)
        disc=10;
    }
    else if(category.equals("HandemadeJewelry")){
        System.out.println("Enter the grams of gold purchased");
        gram=sc.nextInt();
        if(gram<=0){
            System.out.println(gram+ " is an invalid quantity");
            return;
        }
        if(gram>=30)
        disc=8;
    }
    else if(category.equals("NavaratnaJewelry")){
        System.out.println("Enter the grams of gold purchased");
        gram=sc.nextInt();
        if(gram<=0){
            System.out.println(gram +" is an invalid quantity");
            return;
        }
        if(gram>=35)
        disc=13;
    }
    else{
        System.out.println(category+ " is an invalid category");
        return;
    }
    double actualCost = gram*36789;
    if(disc == 0)
    {
        System.out.printf("Total cost is %.2f", actualCost);
    }
    else{
        double discountedCost = actualCost - (actualCost*disc)/100;
        System.out.printf("Total cost is %.2f", discountedCost);
    }
}
}
