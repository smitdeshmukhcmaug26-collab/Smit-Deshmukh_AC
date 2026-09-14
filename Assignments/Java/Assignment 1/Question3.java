class Rectangle{
    private int length;
    private int breadth ;

    Rectangle(int side1, int side2){
        this.length = side1;
        this.breadth = side2;
    }

    public double Area(){
        return this.length * this.breadth;
    }

    void Display(){
        double area = Area();

        System.out.println("Length = " + this.length + " " +"Breadth = " + this.breadth);
        System.out.println("Area of Triangle = " + area);
    }
}

public class Question3 {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(4, 5);
        r1.Display();

        Rectangle r2 = new Rectangle(5, 8);
        r2.Display();
    }
}
