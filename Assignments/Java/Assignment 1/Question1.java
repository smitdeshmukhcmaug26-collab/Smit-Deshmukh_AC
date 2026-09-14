class Student{

    private String name;
    private int roll_no;
    private String address;

    Student(String name, int roll_no, String address){
        this.name = name;
        this.address = address;
        this.roll_no = roll_no;
    }

    public void Display(){
        System.out.println(this.name);
        System.out.println(this.roll_no);
        System.out.println(this.address);
    }

}

public class Question1 {
    public static void main(String[] args) {

        Student s1 = new Student("John", 2, "Mumbai");
        s1.Display();

        Student s2 = new Student("Sam", 3, "Pune");
        s2.Display();
    }
}
