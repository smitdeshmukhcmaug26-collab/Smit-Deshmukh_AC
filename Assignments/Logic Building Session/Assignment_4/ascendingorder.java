import java.util.*;
public class ascendingorder {
    public static void main(String[] args) {
        int[] numbers = new int[5];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 numbers:");

        for (int i = 0 ; i < numbers.length; i++) {
            numbers[i] = input.nextInt();
        }

        Arrays.sort(numbers);
        System.out.println("Numbers in ascending order:");
        for (int num : numbers) {
            System.out.print(num + " ");
        }
    }
}
