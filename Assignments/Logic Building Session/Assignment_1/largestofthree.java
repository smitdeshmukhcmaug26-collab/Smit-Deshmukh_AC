import java.util.Scanner;
public class largestofthree {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the first number: ");
        int a = input.nextInt();
        System.out.print("Please enter the second number: ");
        int b = input.nextInt();
        System.out.print("Please enter the third number: ");
        int c = input.nextInt();

    
        if (a > b && a > c) {
            System.out.println("The largest number is: " + a);
        }
        else if (b > c && b > a) {
            System.out.println("The largest number is: " + b);
        }
        else {
            System.out.println("The largest number is: " + c);
        }
    }
}