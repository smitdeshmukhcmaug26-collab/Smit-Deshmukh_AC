import java.util.Scanner;
public class areaofrectangle {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the length of the rectangle: ");
        int a = input.nextInt();
        System.out.print("Please enter the width of the rectangle: ");
        int b = input.nextInt();
        int area = a * b;
        System.out.println("The area of the rectangle is: " + area);
    }
}