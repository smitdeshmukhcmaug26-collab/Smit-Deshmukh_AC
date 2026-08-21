import java.util.Scanner;
public class goodmorning {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the time: ");
        int time = input.nextInt();
        if (time >= 5 && time < 12) {
            System.out.println("Good morning");
        }
    }
}