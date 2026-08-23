import java.util.*;
public class indexsearch {
    public static void main(String[] args) {
        int[] numbers = new int[5];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 numbers:");

        for (int i = 0 ; i < numbers.length; i++) {
            numbers[i] = input.nextInt();
        }

        System.out.print("Enter a number to search:");
        int searchNum = input.nextInt();
        
        Arrays.sort(numbers);

        int index = Arrays.binarySearch(numbers, searchNum);
        if (index >= 0) {
            System.out.println("Number found at index: " + index);
        } else {
            System.out.println("Number not found in the array.");
        }
    }
}
