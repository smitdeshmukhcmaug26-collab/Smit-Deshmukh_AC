public class pattern1 {
    public static void main(String[] args) {
        
        for(int i = 1; i <= 5; i++) {
            for(int j = 1 ; j <= i; j++) {
                System.out.print(i);
                if(j < i) {
                    System.out.print("*");
                }
            }
            System.out.println();
        }

        for(int a = 5 ; a >= 2; a--) {
                for(int j = 1; j <= a; j++) {
                    System.out.print(a);
                    if(j < a) {
                        System.out.print("*");
                    }
                }
                System.out.println();
        }    
    }
}
