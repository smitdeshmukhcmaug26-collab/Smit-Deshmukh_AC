import java.util.Scanner;
public class negative_no {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter a number: ");
        int a = input.nextInt();
        if (a < 0) {
            System.out.println("The number is negative.");
        } else {
            System.out.println("The number is not negative.");
        }
    }
}