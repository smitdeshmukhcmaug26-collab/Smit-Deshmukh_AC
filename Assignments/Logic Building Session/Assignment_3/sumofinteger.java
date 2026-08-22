public class sumofinteger {
    public static int calculateSum(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = sum + i;
        }
        return sum;
    }

    public static void main(String[] args) {
        int result = sumofinteger.calculateSum(5);
        System.out.println("The sum of integers is: " + result);
    }
}
