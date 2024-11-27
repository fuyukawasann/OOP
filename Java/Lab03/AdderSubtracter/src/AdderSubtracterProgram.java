import javax.swing.JFrame;

public class AdderSubtracterProgram {
    public static void main(String[] args) {
        AdderSubtracterFrame frame1 = new AdderSubtracterFrame("Adder and Subtracter");

        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame1.setSize(400, 100);
        frame1.setVisible(true);
    }
}