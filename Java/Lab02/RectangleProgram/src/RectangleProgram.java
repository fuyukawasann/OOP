import java.util.*;

public class RectangleProgram {
    static Rectangle myRectangle;
    static char commandLetter;
    static double newLocation;

    public static void main(String[] args) {
        myRectangle = new Rectangle();

        while(true)
        {
            printRectangleDetails();
            printMenu();
            getCommand();
            if(commandLetter == 'Q') break;
            getNewLocation();
            updateRectangle();
        }
    }

    public static void printRectangleDetails() {
        System.out.println("Rectangle Info:");
        System.out.println("    Left = " + (int) myRectangle.getLeft() + ", Right = " + (int) myRectangle.getRight()
        + ", Bottom = " + (int) myRectangle.getBottom() + ", Top = " + (int) myRectangle.getTop());
        System.out.println("    Width = " + (int) myRectangle.getWidth() + ", Height = " + (int) myRectangle.getHeight()
        + ", Area = " + (int) myRectangle.getArea());
        System.out.println();
    }

    public static void printMenu()
    {
        System.out.println("Commands:");
        System.out.println("    T) Change Top");
        System.out.println("    B) Change Bottom");
        System.out.println("    L) Change Left");
        System.out.println("    R) Change Right");
        System.out.println("    Q) Quit");
        System.out.println();
    }

    public static void getCommand()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("What do you want to do? ");
        String userString = input.nextLine();
        commandLetter = userString.charAt(0);
        System.out.println();
    }

    public static void getNewLocation()
    {
        if(commandLetter == 'T') System.out.print("What should the top become? ");
        else if(commandLetter == 'B') System.out.print("What should the bottom become? ");
        else if(commandLetter == 'L') System.out.print("What should the left become? ");
        else if(commandLetter == 'R') System.out.print("What should the right become? ");

        Scanner input = new Scanner(System.in);
        newLocation = input.nextDouble();

        System.out.println();
    }

    public static void updateRectangle()
    {
        try {
            if(commandLetter == 'T') myRectangle.setTop(newLocation);
            else if(commandLetter == 'B') myRectangle.setBottom(newLocation);
            else if(commandLetter == 'L') myRectangle.setLeft(newLocation);
            else if(commandLetter == 'R') myRectangle.setRight(newLocation);
        }catch (Exception e) {
            System.out.println();
        }
    }
}