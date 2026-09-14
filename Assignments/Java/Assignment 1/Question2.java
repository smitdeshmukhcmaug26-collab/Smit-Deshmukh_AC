class Triangle{
    private int side1 ;
    private int side2 ;
    private int side3 ;

    Triangle(int side1, int side2, int side3){
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double Area(){
        return 0.5 * (this.side1 * this.side2);
    }

    public double Perimeter(){
        return this.side1 + this.side2 + this.side3;
    }

    void Display(){
        double area = Area();
        double perimeter = Perimeter();

        System.out.println("Area of Triangle = " + area);
        System.out.println("Perimeter of Triangle = " + perimeter);
    }
}

public class Question2 {
    public static void main(String[] args) {

        Triangle t1 = new Triangle(3, 4, 5);
        t1.Display();
    }
}
