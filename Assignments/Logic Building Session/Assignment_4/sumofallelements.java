import java.util.Scanner;
public class sumofallelements {
    public static void main(String[] args) {
        int[] numbers = new int[5];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 numbers:");
        for (int i = 0 ; i < numbers.length; i++) {
            numbers[i] = input.nextInt();
        }

        int sum = 0;
        for (int num : numbers) {
            sum = sum + num;
        }
        System.out.println("Sum of all elements: " + sum);
    }
    
}