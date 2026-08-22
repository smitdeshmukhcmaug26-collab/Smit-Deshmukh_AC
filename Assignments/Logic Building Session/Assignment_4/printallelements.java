import java.util.Scanner;

public class printallelements {
    public static void main(String[] args) {
        String[] names = new String[5];
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 names:");
        for (int i = 0 ; i < names.length; i++) {
            names[i] = input.nextLine();
        }

        for (String name : names) {
            System.out.println(name);
        }
    }
}