import java.util.Scanner;

public class agechecker {
    public static String checkAgeCategory(int age) {
        if (age < 18) {
            return "You are a minor.";
        } else {
                return "You are an adult.";
            }
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your age: ");
        int age = input.nextInt();
        String category = agechecker.checkAgeCategory(age);
        System.out.println(category);
    }
}