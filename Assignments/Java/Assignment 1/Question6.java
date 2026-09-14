import java.util.Scanner;

class Employee2 {
    private String name;
    private double salary;
    private int hoursOfWork;


    public Employee2() {
        this.name = "Unassigned";
        this.salary = 0.0;
        this.hoursOfWork = 0;
    }

    public Employee2(String name) {
        setName(name);
        this.salary = 0.0;
        this.hoursOfWork = 0;
    }

    public void getInfo(double salary, int hoursOfWork) {
        setSalary(salary);
        setHoursOfWork(hoursOfWork);
    }

    public void addSal() {
        if (this.salary < 500) {
            this.salary += 10;
        }
    }

    public void addWork() {
        if (this.hoursOfWork > 6) {
            this.salary += 5;
        }
    }

    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            this.name = "Unassigned";
        } else {
            this.name = name;
        }
    }

    public String getName() {
        return name;
    }

    public void setSalary(double salary) {
        if (salary >= 0) {
            this.salary = salary;
        }
    }

    public double getSalary() {
        return salary;
    }

    public void setHoursOfWork(int hoursOfWork) {
        if (hoursOfWork >= 0) {
            this.hoursOfWork = hoursOfWork;
        }
    }

    public int getHoursOfWork() {
        return hoursOfWork;
    }
}

public class Question6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Employee Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Salary ($): ");
        double salary = sc.nextDouble();

        System.out.print("Enter Work Hours per Day: ");
        int hours = sc.nextInt();

        Employee2 emp = new Employee2(name);

        emp.getInfo(salary, hours);
        emp.addSal();
        emp.addWork();

        System.out.println("Name: " + emp.getName());
        System.out.println("Final Salary: $" + emp.getSalary());

    }
}
