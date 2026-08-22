import java.util.Scanner;
public class sumoftwonos {
    public static int sum(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int a = input.nextInt();
        System.out.print("Enter the second number: ");
        int b = input.nextInt();
        
        int result = sumoftwonos.sum(a, b);
        System.out.println("The sum of " + a + " and " + b + " is: " + result);
    }
}