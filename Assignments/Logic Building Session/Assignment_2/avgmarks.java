public class avgmarks {
    public static void main(String[] args) {
        int Maths = 80;
        int Science = 85;
        int History = 90;
        double average = (Maths + Science + History) / 3;
        System.out.println("The average marks are: " + average);

        if(average >= 90) {
            System.out.println("Grade: A");
        } else if(average >= 70 && average <= 89) {
            System.out.println("Grade: B");
        } else if(average >= 50 && average <= 69) {
            System.out.println("Grade: C");
        } else if(average >= 30 && average <= 49) {
            System.out.println("Grade: D");
        } else {
            System.out.println("Fail");
        }
    }
    
}