 import java.util.Scanner;

public class findposiandneg {
    public static void main(String[] args) {
        int[] numbers = new int[6];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 6 numbers:");
        for (int i = 0 ; i < numbers.length; i++) {
            numbers[i] = input.nextInt();
        }

        for (int num : numbers) {
            if (num < 0){
                System.out.println("Negative number: " + num);
            } else {
                System.out.println("Positive number: " + num);
            }
        }
        
    }
}

