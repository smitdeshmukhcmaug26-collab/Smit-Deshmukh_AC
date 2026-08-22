import java.util.Scanner;

public class positivenumbers {
    public static int askForPositiveNumber() {
        Scanner input = new Scanner(System.in);
        int number;
        do{
            System.out.print("Please enter a positive number: ");
            number = input.nextInt();
        }
        while(number <= 0);

        return number;
    }

    public static void main(String[] args) {
        int positiveNumber = positivenumbers.askForPositiveNumber();
        System.out.println("You entered: " + positiveNumber);
    }
}