import javax.swing.*;

public class SnowflakeProgram {
    public static void main(String[] args){
        SnowflakeFrame frame1 = new SnowflakeFrame("Drawing Snowflakes");

        frame1.setVisible(true);
        frame1.setSize(300,350);
        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
