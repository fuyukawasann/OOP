import java.util.Scanner;

public class TriangleArea {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double height;
        double width;
        double area;

        System.out.print("Enter the height of the triangle:");
        height = input.nextDouble();
        System.out.print("Enter the width of the triangle:");
        width = input.nextDouble();

        // Find the corner case
        if(height < 0) {
            System.out.println("The height is less than 0");
        }
        else if(width < 0)
        {
            System.out.println("The width is less than 0");
        }
        else {
            area = height * width / 2;
            System.out.printf("The area is %f\n", area);
        }
    }
}