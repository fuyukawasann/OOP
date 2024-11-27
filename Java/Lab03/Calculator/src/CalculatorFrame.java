import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculatorFrame extends JFrame {
    private JTextField num1TextField;
    private JTextField num2TextField;
    private JTextField resultTextField;
    private JButton clearButton;
    private JButton addButton;
    private JButton subtractButton;
    private JButton multiplyButton;
    private JButton divideButton;
    private JButton logButton;
    private JButton powButton;
    private JButton sqrtButton;
    private JPanel buttonRow1;
    private JPanel buttonRow2;

    public CalculatorFrame(String title) {
        super(title);

        setLayout(new GridLayout(3, 2, 5, 5));

        num1TextField = new JTextField("0", 5);
        num2TextField = new JTextField("0", 5);
        resultTextField = new JTextField(5);
        buttonRow1 = getButtonRow(1);
        buttonRow2 = getButtonRow(2);

        add (num1TextField);
        add (buttonRow1);
        add (num2TextField);
        add (buttonRow2);
        add (resultTextField);
        clearButton = new JButton("CLEAR");
        clearButton.addActionListener(new ButtonListener());
        add (clearButton);

    }

    private JPanel getButtonRow(int type)
    {
        JPanel myPanel = new JPanel();
        myPanel.setLayout(new FlowLayout());

        ButtonListener listener = new ButtonListener();

        // type 1 - + , -, *, /
        if(type == 1)
        {
            addButton = new JButton("+");
            subtractButton = new JButton("-");
            multiplyButton = new JButton("*");
            divideButton = new JButton("/");

            addButton.addActionListener(listener);
            subtractButton.addActionListener(listener);
            multiplyButton.addActionListener(listener);
            divideButton.addActionListener(listener);

            myPanel.add(addButton);
            myPanel.add(subtractButton);
            myPanel.add(multiplyButton);
            myPanel.add(divideButton);
        }

        // type 2 - LOG, POW, SQRT
        if(type == 2)
        {
            logButton = new JButton("LOG");
            powButton = new JButton("POW");
            sqrtButton = new JButton("SQRT");

            logButton.addActionListener(listener);
            powButton.addActionListener(listener);
            sqrtButton.addActionListener(listener);

            myPanel.add(logButton);
            myPanel.add(powButton);
            myPanel.add(sqrtButton);


        }

        return myPanel;

    }

    private class ButtonListener implements ActionListener {

        public void actionPerformed(ActionEvent event) {
            double num1, num2, result = 0;

            // CLEAR
            if(event.getSource() == clearButton)
            {
                num1TextField.setText("0");
                num2TextField.setText("0");
                resultTextField.setText("");
            }
            else {
                try {
                    num1 = Double.parseDouble(num1TextField.getText());
                    num2 = Double.parseDouble(num2TextField.getText());
                }
                catch (NumberFormatException error) {
                    JOptionPane.showMessageDialog(null, "Please Enter an integer");
                    return;
                }

                // add
                if(event.getSource() == addButton)
                {
                    result = num1 + num2;
                }
                // subtract
                if(event.getSource() == subtractButton)
                    result = num1 - num2;
                // multiply
                if(event.getSource() == multiplyButton)
                    result = num1 * num2;
                // div
                if(event.getSource() == divideButton)
                {
                    try {
                        result = num1 / num2;
                    }
                    catch (ArithmeticException error) {
                        JOptionPane.showMessageDialog(null, "Cannot divide by zero");
                        return;
                    }
                }
                if(event.getSource() == logButton)
                {
                    // 하나의 입력이 있을 때
                    try {
                        if(num1 <= 0 || num2 <= 0) throw(new LessThanZeroException());
                        else if(num1 == 1) throw (new ArithmeticException());
                        else result = Math.log(num2) / Math.log(num1);

                    }catch (LessThanZeroException error)
                    {
                        JOptionPane.showMessageDialog(null, "Input cannot be less or equal than zero");
                        return;
                    }
                    catch (ArithmeticException error)
                    {
                        JOptionPane.showMessageDialog(null, "Log base cannot be equal as one");
                        return;
                    }
                }
                if(event.getSource() == powButton)
                {
                    result = Math.pow(num1, num2);
                }
                if(event.getSource() == sqrtButton)
                {
                    try{
                        if(num1 < 0) throw(new LessThanZeroException());
                        else result = Math.sqrt(num1);
                    } catch(LessThanZeroException error)
                    {
                        JOptionPane.showMessageDialog(null, "Input cannot be less than zero");
                        return;
                    }
                }

                resultTextField.setText(String.format("%f", result));
            }
        }
    }
}
