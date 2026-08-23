import java.util.*;
public class arraysearch {
    public static void main(String[] args) {
        Integer[] numbers = new Integer[5];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 numbers:");

        for (int i = 0 ; i < numbers.length; i++) {
            numbers[i] = input.nextInt();
        }

        System.out.print("Enter a number to search:");
        int searchNum = input.nextInt();
        

        if (Arrays.asList(numbers).contains(searchNum)) {
            System.out.println("Number found: " + searchNum);
        } else {
            System.out.println("Number not found: " + searchNum);
        }
    }    
}
