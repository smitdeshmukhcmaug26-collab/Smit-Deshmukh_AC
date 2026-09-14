class Employee{
    private String name;
    private int year_of_joining;
    private double salary;
    private String address;

    Employee(){
        this.name = name;
        this.address = address;
        this.salary = salary;
        this.year_of_joining = year_of_joining;
    }

    public void setAddress(String address) {
        if (address.isEmpty()) {
            this.address = "Unassigned";
        } else {
            this.address = address;
        }
    }

    public String getAddress() {
        return address;
    }

    public void setName(String name) {
        if (name.isEmpty()) {
            this.name = "Unassigned";
        } else {
            this.name = name;
        }
    }

    public String getName() {
        return name;
    }

    public void setSalary(double salary) {
        if(salary > 10000) {
            this.salary = salary;
        }
        else {
            this.salary = 10000;
        }
    }

    public double getSalary() {
        return salary;
    }

    public void setYear_of_joining(int year_of_joining) {
        if(year_of_joining > 0) {
            this.year_of_joining = year_of_joining;
        }
    }

    public int getYear_of_joining() {
        return year_of_joining;
    }

    void Display(){
        String name = getName();
        String address = getAddress();
        double salary = getSalary();
        int year = getYear_of_joining();

        System.out.println("Name" + "     Year_of_joining     " + "Address");
        System.out.println(name + "     " + year + "        " + address);
    }
}
public class Question5 {
    public static void main(String[] args) {
        Employee e1 = new Employee();
        e1.setName("Smit");
        e1.setYear_of_joining(1990);
        e1.setAddress("Pen");
        e1.Display();
    }
}
