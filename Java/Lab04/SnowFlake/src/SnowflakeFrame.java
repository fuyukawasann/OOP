import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;

public class SnowflakeFrame extends JFrame{
    JSlider mySlider;
    SnowflakePanel myPanel;
    public SnowflakeFrame(String title) {
        super(title);
        mySlider = new JSlider(0,100);
        mySlider.setPaintTicks(true);
        mySlider.setMajorTickSpacing(100);
        myPanel = new SnowflakePanel();
        myPanel.setBackground(Color.WHITE);
        mySlider.addChangeListener(
                new ChangeListener() {
                    public void stateChanged(ChangeEvent e) {
                        myPanel.setSpacing(mySlider.getValue());
                    }
                }
        );
        add(mySlider, BorderLayout.SOUTH);
        add(myPanel, BorderLayout.CENTER);
    }
}
