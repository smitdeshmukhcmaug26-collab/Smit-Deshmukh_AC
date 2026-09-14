import java.util.Scanner;

class Complex{

    private int real ;
    private int imaginary;

    public Complex(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public void setReal(int real) {
        this.real = real;
    }

    public int getReal() {
        return real;
    }

    public void setImaginary(int imaginary) {
        this.imaginary = imaginary;
    }

    public int getImaginary() {
        return imaginary;
    }

    public String Sum(Complex other) {
        int newReal = this.real + other.real;
        int newImaginary = this.imaginary + other.imaginary;

        if (newImaginary >= 0) {
            return newReal + " + " + newImaginary + "i";
        } else {
            return newReal + " - " + Math.abs(newImaginary) + "i";
        }
    }

    public String Difference(Complex other) {
        int newReal = this.real - other.real;
        int newImaginary = this.imaginary - other.imaginary;

        if (newImaginary >= 0) {
            return newReal + " + " + newImaginary + "i";
        } else {
            return newReal + " - " + Math.abs(newImaginary) + "i";
        }
    }

    public String Product(Complex other) {
        int newReal = (this.real * other.real) - (this.imaginary * other.imaginary);
        int newImaginary = (this.real * other.imaginary) + (this.imaginary * other.real);

        if (newImaginary >= 0) {
            return newReal + " + " + newImaginary + "i";
        } else {
            return newReal + " - " + Math.abs(newImaginary) + "i";
        }
    }

    public void Display(Complex other){
        String Sum = Sum(other);
        String Product = Product(other);
        String Differrence = Difference(other);

        System.out.println("Sum of complex numbers : " + Sum);
        System.out.println("Difference of complex numbers : " + Differrence);
        System.out.println("Product of complex numbers : " + Product);
    }
}

public class Question4 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first real no. : ");
        int r1 = sc.nextInt();
        System.out.print("Enter first imaginary no. : ");
        int i1 = sc.nextInt();

        System.out.println("First Complex no.: " + r1 + " + " + i1 + "i");

        Complex c1 = new Complex(r1, i1);

        System.out.print("Enter first real no. : ");
        int r2 = sc.nextInt();
        System.out.print("Enter first imaginary no. : ");
        int i2 = sc.nextInt();

        System.out.println("First Complex no.: " + r2 + " + " + i1 + "i");

        Complex c2 = new Complex(r2, i2);

        c1.Display(c2);

    }
}
