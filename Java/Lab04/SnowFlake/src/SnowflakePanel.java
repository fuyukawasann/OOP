import javax.swing.*;
import java.awt.*;

public class SnowflakePanel extends JPanel{
    int minimumRadius = 10;
    public void paintCenteredStar(Graphics g, int xCenter, int yCenter, int radius)
    {
        g.setColor(Color.CYAN);
        g.drawLine(xCenter - radius, yCenter, xCenter + radius, yCenter);
        g.drawLine(xCenter - radius / 2, yCenter - (int)(radius * Math.sqrt(3) / 2),
                xCenter + radius / 2, yCenter + (int)(radius * Math.sqrt(3) / 2));
        g.drawLine(xCenter + radius / 2, yCenter - (int)(radius * Math.sqrt(3) / 2),
                xCenter - radius / 2, yCenter + (int)(radius * Math.sqrt(3) / 2));
    }
    public void paintSnowflake(Graphics g, int xCenter, int yCenter, int radius)
    {
        if (radius <= minimumRadius) return;
        paintCenteredStar(g, xCenter, yCenter, radius);
        paintSnowflake(g, xCenter - radius, yCenter, radius/3);
        paintSnowflake(g, xCenter + radius, yCenter, radius/3);
        paintSnowflake(g, xCenter - radius / 2, yCenter - (int)(radius * Math.sqrt(3) / 2), radius/3);
        paintSnowflake(g, xCenter + radius / 2, yCenter + (int)(radius * Math.sqrt(3) / 2), radius/3);
        paintSnowflake(g, xCenter + radius / 2, yCenter - (int)(radius * Math.sqrt(3) / 2), radius/3);
        paintSnowflake(g, xCenter - radius / 2, yCenter + (int)(radius * Math.sqrt(3) / 2), radius/3);
    }
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        paintSnowflake (g, 150, 150, 100);
    }
    public void setSpacing(int newMinRadius)
    {
        minimumRadius = newMinRadius;
        repaint();
    }
}
