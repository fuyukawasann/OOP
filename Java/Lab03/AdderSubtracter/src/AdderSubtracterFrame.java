import javax.swing.*;
import javax.swing.plaf.basic.BasicOptionPaneUI;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AdderSubtracterFrame extends JFrame {
    private JTextField num1TextField;
    private JTextField num2TextField;
    private JTextField resultTextField;
    private JButton clearButton;
    private JButton addButton;
    private JButton subtractButton;
    private JPanel buttonPanel;



    public AdderSubtracterFrame(String title) {
        super(title);

        setLayout(new GridLayout(2,2,5,5));

        num1TextField = new JTextField("0", 5);
        num2TextField = new JTextField("0", 5);
        resultTextField = new JTextField(5);
        buttonPanel = getButtonPanel();

        add (num1TextField);
        add (num2TextField);
        add (resultTextField);
        add(buttonPanel);
    }

    private JPanel getButtonPanel() {
        JPanel myPanel = new JPanel();
        myPanel.setLayout(new FlowLayout());

        addButton = new JButton("+");
        subtractButton = new JButton("-");
        clearButton = new JButton("CLEAR");

        ButtonListener listener = new ButtonListener();

        addButton.addActionListener(listener);
        subtractButton.addActionListener(listener);
        clearButton.addActionListener(listener);

        myPanel.add(addButton);
        myPanel.add(subtractButton);
        myPanel.add(clearButton);

        return myPanel;
    }


    private class ButtonListener implements ActionListener {

        public void actionPerformed(ActionEvent event)
        {
            int num1, num2, result = 0;

            if(event.getSource() == clearButton)
            {
                num1TextField.setText("0");
                num2TextField.setText("0");
                resultTextField.setText("");
            }
            else
            {
                num1 = Integer.parseInt(num1TextField.getText());
                num2 = Integer.parseInt(num2TextField.getText());

                if(event.getSource() == addButton)
                {
                    result = num1 + num2;
                }
                if(event.getSource() == subtractButton)
                {
                    result = num1 - num2;
                }

                resultTextField.setText(String.format("%d", result));
            }
        }
    }
}



