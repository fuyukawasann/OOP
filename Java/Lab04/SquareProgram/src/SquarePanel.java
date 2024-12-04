import javax.swing.*;
import java.awt.*;

public class SquarePanel extends JPanel {
    int spacing = 10;

    public void paintCenteredSquare(Graphics g, int xCenter, int yCenter,int sideLength)
    {
        int x = xCenter - sideLength/2;
        int y = yCenter - sideLength/2;
        int height = sideLength;
        int width = sideLength;

        g.setColor(Color.RED);
        g.drawRect(x, y, width, height);

    }

    public void paintInscribedSquares(Graphics g, int xCenter, int yCenter, int sideLength)
    {
        if (sideLength <= 0) return;
        paintCenteredSquare(g, xCenter, yCenter, sideLength);
        paintInscribedSquares(g, xCenter, yCenter, sideLength - spacing);
    }

    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);

        paintInscribedSquares(g, 150, 150, 250);
    }

    public void setSpacing(int newSpacing)
    {
        spacing = newSpacing;
        repaint();
    }
}
