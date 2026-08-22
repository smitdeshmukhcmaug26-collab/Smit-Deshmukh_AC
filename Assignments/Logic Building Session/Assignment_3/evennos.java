public class evennos {
    public static void main(String[] args) {
        System.out.println("Even numbers from 1 to 50:");
        int i = 1;
        while (i <= 50){
            if(i % 2 == 0){
                System.out.println(i);
            }
            i++;
        }
    }
}