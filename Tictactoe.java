import java.util.Scanner;
public class Tictactoe{
    static int arr[] = new int[2];
    static char[][] box = new char[3][3];
    static int tru=0;
    static int l=0,m=0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //char[][] box = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                box[i][j] = '-';
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(box[i][j] + " ");
            }
            System.out.println("");
        }

        String player1, player2;
        System.out.print("choose charecter('x' or 'o') for player1 : ");
        player1 = sc.nextLine();
        System.out.print("choose the remaining charecter('x' or 'o') for player 2 : ");
        player2 = sc.nextLine();

        System.out.print("enter '1':if player 1 should start first or '2' if player should start : ");

        String p;
        int temp=0;
        p=sc.nextLine();
        if(p.charAt(0)=='1')
        {
            temp=1;
        }
        else
        {
            temp=2;
        }
        int winner=0,win=0;
        System.out.println("kindly assume the positions as a 2d array 00 01 02/10 11 12/20 21 22");
        for(int i=0;i<6;i++) {
            if(temp==1) {
                int p1;
                System.out.print("enter the position u want to place your "+player1.charAt(0) +" ");
                p1 = sc.nextInt();
                position(p1);
                box[m][l] = player1.charAt(0);
                display();
                winner=1;
                temp=2;
            }
            else {
                int p2;
                System.out.print("enter the position u want to place your "+player2.charAt(0) +" ");
                p2 = sc.nextInt();
                position(p2);
                box[m][l] = player2.charAt(0);
                display();
                winner=2;
                temp=1;
            }
            check();
            if(tru==1) {
                win=1;
                break;
            }
        }
        if(winner==1 && win==1) {
            System.out.print("hurrah!player1 is winner");
        }
        else if(winner==2 && win==1)
        {
            System.out.print("hurrah! player 2 is winner");
        }
    }

    public static void position(int num) {
        int p1;
        p1=num;
        p1 = num % 10;
        l=p1;
        //System.out.print(l);
        num = num/10;
        num=num%10;
        m=num;
        //System.out.print(m);
    }
    public static void check(){
        if(((int)box[0][0]==120 && (int)box[0][1]==120 && (int)box[0][2]==120 )||((int)box[0][0]==111 && (int)box[0][1]==111 && (int)box[0][2]==111) ){
            tru=1;
        }
        else if(((int)box[1][0]==120 && (int)box[1][1]==120 && (int)box[1][2]==120 )||((int)box[1][0]==111 && (int)box[1][1]==111 && (int)box[1][2]==111 )) {
            tru=1;
        }
        else if(((int)box[2][0]==120 && (int)box[2][1]==120 && (int)box[2][2]==120 )||((int)box[2][0]==111 && (int)box[2][1]==111 && (int)box[2][2]==111 )){
            tru=1;
        }
        else if(((int)box[0][0]==120 && (int)box[1][0]==120 && (int)box[2][0]==120 )||((int)box[0][1]==111 && (int)box[1][0]==111 && (int)box[2][0]==111 )){
            tru=1;
        }
        else if(((int)box[0][1]==120 && (int)box[1][1]==120 && (int)box[2][1]==120 )||((int)box[0][1]==111 && (int)box[1][1]==111 && (int)box[2][1]==111 )){
            tru=1;
        }
        else if(((int)box[0][2]==120 && (int)box[1][2]==120 && (int)box[2][2]==120 )||((int)box[0][2]==111 && (int)box[1][2]==111 && (int)box[2][2]==111 )){
            tru=1;
        }
        else if(((int)box[0][0]==120 && (int)box[1][1]==120 && (int)box[2][2]==120 )||((int)box[0][0]==111 && (int)box[1][1]==111 && (int)box[2][2]==111 )){
            tru=1;
        }
        else if(((int)box[0][2]==120 && (int)box[1][1]==120 && (int)box[2][0]==120 )||((int)box[0][2]==111 && (int)box[1][1]==111 && (int)box[2][0]==111 )){
            tru=1;
        }

    }
    public static void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(box[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
