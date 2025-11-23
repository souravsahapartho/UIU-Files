
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class BankAccountApp implements ActionListener {
    //ArrayList
    private static final ArrayList<BankAccount> accounts = new ArrayList<>();
    //UI components
    JFrame f = new JFrame("Banking App");
    JPanel p = new JPanel();
    JTextField searchbar = new JTextField();
    JTextField deposit = new JTextField();
    JTextField withdraw = new JTextField();

    JLabel name = new JLabel("");
    JLabel balance = new JLabel("");
    JLabel lastT = new JLabel("");
    JLabel lastTtype = new JLabel("");

    JButton searchButton = new JButton("Search");
    JButton depositButton = new JButton("Search");
    JButton withdrawButton = new JButton("Search");

    public void seProperties(){
        /***
         * Design your GUI here - 5 marks
         */
        f.setVisible(true);
    }

    public static void main(String[] args) {
        /***
         * Insert data into ArrayList -5 marks
         * Sort the ArrayList - 5 Marks
         */

        //Launch GUI
       BankAccountApp app = new BankAccountApp();
       app.seProperties();

    }


    @Override
    public void actionPerformed(ActionEvent e) {
        /***
         * Write Event Handling code here - 5 Marks
         */
    }
}
