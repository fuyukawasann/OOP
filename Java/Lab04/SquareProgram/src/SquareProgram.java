import javax.swing.*;
import java.awt.*;

public class SquareProgram {
    public static void main(String[] args) {
//        JFrame frame1 = new JFrame("Drawing Squares");
//
//        SquarePanel panel1 = new SquarePanel();
//        panel1.setBackground(Color.WHITE);
//
//        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        frame1.add(panel1);
//        frame1.setSize(300, 325);
//        frame1.setVisible(true);

        SquareFrame frame = new SquareFrame("Drawing Squares");
        frame.setVisible(true);
        frame.setSize(300, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}