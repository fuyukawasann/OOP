import javax.swing.JFrame;

public class CalculatorProgram {
    public static void main(String[] args) {
        CalculatorFrame frame1 = new CalculatorFrame("Calculator");

        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame1.setSize(700, 200);
        frame1.setVisible(true);

    }
}