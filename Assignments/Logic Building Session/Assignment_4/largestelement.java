import java.util.*;
public class largestelement {
    public static void main(String[] args) {
        int[] numbers = new int[5];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 numbers:");
        for (int i = 0 ; i < numbers.length; i++) {
            numbers[i] = input.nextInt();
        }

        int largest = Arrays.stream(numbers).max().getAsInt();
        System.out.println("Largest element: " + largest);
        
    }
}