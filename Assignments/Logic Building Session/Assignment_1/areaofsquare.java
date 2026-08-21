import java.util.Scanner;
public class areaofsquare {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the length of the square: ");
        int a = input.nextInt();
        int area = a * a;
        System.out.println("The area of the square is: " + area);
    }
}