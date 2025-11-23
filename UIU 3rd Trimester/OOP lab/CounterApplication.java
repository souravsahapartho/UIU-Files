package class_11;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CounterApplication implements ActionListener {
    //1.Create the components
    JFrame f = new JFrame("Counter");
    JPanel p = new JPanel();
    JTextField tf = new JTextField("0");
    JLabel l = new JLabel("count:");
    JButton b1 = new JButton("+");
    JButton b2 = new JButton("-");

    public void setProperties(){
        tf.setBounds(150,100,100,20);
        l.setBounds(100,100,100,20);
        b1.setBounds(175,150,50,50);
        b2.setBounds(175,220,50,50);
        b1.addActionListener(this);
        b2.addActionListener(this);

        p.add(tf);
        p.add(b1);
        p.add(b2);
        p.add(l);
        p.setLayout(null);
        p.setBackground(Color.cyan);

        f.setSize(400,400);
        f.add(p);
        f.setResizable(false);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        CounterApplication c = new CounterApplication();
        c.setProperties();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        //Application Logic
        if(e.getSource() == b1){
            String s = tf.getText();
            int i = Integer.parseInt(s);
            i++;
            String output = String.valueOf(i);
            tf.setText(output);
        }
        else if (e.getSource() == b2) {
            String s = tf.getText();
            int i = Integer.parseInt(s);
            if(i>0) i--;
            String output = String.valueOf(i);
            tf.setText(output);
        }
    }
}
