public class multiplicationtable {
    public static void printMultiplicationTable(int n) {
        for (int i = 1; i <= 10; i++) {
            int result = n * i;
            System.out.println(result);
        }
    }
    
    public static void main(String[] args) {
        multiplicationtable.printMultiplicationTable(5);
    }    
}