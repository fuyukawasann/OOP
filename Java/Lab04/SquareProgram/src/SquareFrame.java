import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;

public class SquareFrame extends JFrame {
    JSlider mySlider;
    SquarePanel myPanel;

    public SquareFrame(String title)
    {
        super(title);

        mySlider = new JSlider();
        mySlider.setPaintTicks(true);
        mySlider.setMajorTickSpacing(20);

        myPanel = new SquarePanel();
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
