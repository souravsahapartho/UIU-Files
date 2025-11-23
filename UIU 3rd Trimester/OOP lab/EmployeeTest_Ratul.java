//package final_problemset;
//
//import javax.swing.*;
//import java.awt.*;
//import java.awt.event.ActionEvent;
//import java.awt.event.ActionListener;
//import java.util.ArrayList;
//
//public class EmployeeTest
//{
//    public static void main(String[] args) {
//        ArrayList<Employee> al=new ArrayList<>();
//        frame f=new frame(al);
//        f.setProperties();
//        f.setVisible(true);
//
//        f.dispose();
//
//
//
//
//    }
//
//
//
//}
//class Employee{
//    String name;
//    int age;
//    double salary;
//    String phn;
//
//    public Employee(String name, int age, double salary, String phn) {
//        this.name = name;
//        this.age = age;
//        this.salary = salary;
//        this.phn = phn;
//    }
//
//    @Override
//    public String toString() {
//        return "Employee{" +
//                "name='" + name + '\'' +
//                ", age=" + age +
//                ", salary=" + salary +
//                ", phn='" + phn + '\'' +
//                '}';
//    }
//}
//
//class frame2 extends JFrame implements ActionListener{
//    ArrayList<Employee> al;
//
//    public frame2(ArrayList<Employee> al) throws HeadlessException {
//        this.al = al;
//    }
//
//    JFrame f=new JFrame("Salary Increment");
//    JPanel p=new JPanel();
//    JTextField tf1=new JTextField("15000");
//    JTextField tf2=new JTextField();
//
//    JButton b=new JButton("Increment");
//
//    JLabel l1=new JLabel("Current Salary");
//    JLabel l2=new JLabel("Percentage");
//
//    void setProperties(){
////        f.setVisible(true);
//        f.setSize(400,400);
//        f.setLayout(null);
//        f.setResizable(false);
//        f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//        p.setLayout(null);
//
//
//        p.add(tf1);
//        p.add(tf2);
//        tf1.setBounds(250,50,100,40);
//        tf2.setBounds(250,110,100,40);
//
//        b.setBounds(270,150,80,40);
//        b.addActionListener(this);
//
//
//
//
//
//
//        f.add(p);
//        p.add(l1);
//        p.add(l2);
//        p.add(b);
//
//
//
//
//    }
//
//
//
//    @Override
//    public void actionPerformed(ActionEvent e) {
//        if(e.getSource()==b){
//            int per;
//            String p=tf1.getText().replace("%","");
//            per=Integer.parseInt(p);
//            al.get(0).salary=al.get(0).salary+(al.get(0).salary*0.15);
//
//            System.out.println(al.getFirst());
//
//
//
//
//        }
//
//
//    }
//}
//
//
//class frame extends JFrame implements ActionListener{
//
//
//
//
//
//    JFrame f=new JFrame("Employee Registration");
//    JPanel p=new JPanel();
//    JTextField tf1=new JTextField();
//    JTextField tf2=new JTextField();
//    JTextField tf3=new JTextField();
//    JTextField tf4=new JTextField();
//
//
//    JLabel l1=new JLabel("Name");
//    JLabel l2=new JLabel("Age");
//    JLabel l3=new JLabel("Salary");
//    JLabel l4=new JLabel("Phone");
//
//    JButton b=new JButton("REGISTER");
//
//
//
//
//    public void setProperties(){
//        f.add(p);
//        f.setSize(500,500);
//        f.setVisible(true);
//        f.setLayout(null);
//        f.setResizable(false);
//        f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//
//
//        p.setLayout(null);
//        p.add(tf1);
//        p.add(tf2);
//        p.add(tf3);
//        p.add(tf4);
//
//        p.setBackground(Color.gray);
//        p.add(l1);
//        p.add(l2);
//        p.add(l3);
//        p.add(l4);
//
//        p.add(b);
//        b.setBounds(200,290,130,40);
//        b.addActionListener(this);
//
//
//
//
//
//
//        tf1.setBounds(150,50,200,40);
//        l1.setBounds(70,50,60,40);
//
//        tf2.setBounds(150,110,200,40);
//        l2.setBounds(70,110,60,40);
//
//        tf3.setBounds(150,170,200,40);
//        l3.setBounds(70,170,60,40);
//
//        tf4.setBounds(150,230,200,40);
//        l4.setBounds(70,230,60,40);
//
//
//
//
//
//
//
//
//    }
//
//    public ArrayList<Employee> al;
//
//    public frame(ArrayList<Employee> al) throws HeadlessException {
//        this.al = al;
//    }
//
//    @Override
//    public void actionPerformed(ActionEvent e) {
//        if(e.getSource()==b)
//        {
//            String name = tf1.getText().isEmpty() ? "Unknown" : tf1.getText();
//            int age = tf2.getText().isEmpty() ? 0 : Integer.parseInt(tf2.getText());
//            double salary = tf3.getText().isEmpty() ? 0.0 : Double.parseDouble(tf3.getText());
//            String phone = tf4.getText().isEmpty() ? "Unknown" : tf4.getText();
//
//            Employee ex = new Employee(name, age, salary, phone);
//            al.add(ex);
//
//            this.dispose();
//            frame2 f2=new frame2(al);
//            f2.setProperties();
//
//
//
//
//
//        }
//
//
//
//
//
//
//    }
//    public void showw(){
//        System.out.println(al.getFirst());
//    }
//}


package final_problemset;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class EmployeeTest {
    public static void main(String[] args) {
        ArrayList<Employee> al = new ArrayList<>();
        Frame f = new Frame(al);
        f.setProperties();
        f.setVisible(true);
    }
}

class Employee {
    String name;
    int age;
    double salary;
    String phn;

    public Employee(String name, int age, double salary, String phn) {
        this.name = name;
        this.age = age;
        this.salary = salary;
        this.phn = phn;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", salary=" + salary +
                ", phn='" + phn + '\'' +
                '}';
    }
}

class Frame2 extends JFrame implements ActionListener {
    ArrayList<Employee> al;
    JPanel p = new JPanel();
    JTextField tf1 = new JTextField("15000");
    JTextField tf2 = new JTextField();
    JButton b = new JButton("Increment");

    public Frame2(ArrayList<Employee> al) {
        this.al = al;
        setTitle("Salary Increment");
        setSize(400, 400);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        p.setLayout(null);

        JLabel l1 = new JLabel("Current Salary");
        JLabel l2 = new JLabel("Percentage");

        l1.setBounds(50, 50, 100, 40);
        l2.setBounds(50, 110, 100, 40);
        tf1.setBounds(150, 50, 100, 40);
        tf2.setBounds(150, 110, 100, 40);
        b.setBounds(150, 170, 100, 40);
        b.addActionListener(this);

        p.add(l1);
        p.add(l2);
        p.add(tf1);
        p.add(tf2);
        p.add(b);
        add(p); // Add panel to frame
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b) {
            int per;
            String p = tf2.getText().replace("%", "");
            per = Integer.parseInt(p);
            al.get(0).salary += al.get(0).salary * (per / 100.0); // Calculate increment based on percentage

            System.out.println(al.get(0)); // Print updated employee info
        }
    }
}

class Frame extends JFrame implements ActionListener {
    ArrayList<Employee> al;
    JPanel p = new JPanel();
    JTextField tf1 = new JTextField();
    JTextField tf2 = new JTextField();
    JTextField tf3 = new JTextField();
    JTextField tf4 = new JTextField();
    JButton b = new JButton("REGISTER");

    public Frame(ArrayList<Employee> al) {
        this.al = al;
    }

    public void setProperties() {
        setTitle("Employee Registration");
        setSize(500, 500);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
//        setLayout(null);

        JLabel l1 = new JLabel("Name");
        JLabel l2 = new JLabel("Age");
        JLabel l3 = new JLabel("Salary");
        JLabel l4 = new JLabel("Phone");

        l1.setBounds(70, 50, 60, 40);
        tf1.setBounds(150, 50, 200, 40);
        l2.setBounds(70, 110, 60, 40);
        tf2.setBounds(150, 110, 200, 40);
        l3.setBounds(70, 170, 60, 40);
        tf3.setBounds(150, 170, 200, 40);
        l4.setBounds(70, 230, 60, 40);
        tf4.setBounds(150, 230, 200, 40);
        b.setBounds(200, 290, 130, 40);
        b.addActionListener(this);

        p.setLayout(null);
        p.setBackground(Color.gray);

        p.add(l1);
        p.add(tf1);
        p.add(l2);
        p.add(tf2);
        p.add(l3);
        p.add(tf3);
        p.add(l4);
        p.add(tf4);
        p.add(b);
        add(p);
        setVisible(true);// Add panel to frame
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b) {
            String name = tf1.getText().isEmpty() ? "Unknown" : tf1.getText();
            int age = tf2.getText().isEmpty() ? 0 : Integer.parseInt(tf2.getText());
            double salary = tf3.getText().isEmpty() ? 0.0 : Double.parseDouble(tf3.getText());
            String phone = tf4.getText().isEmpty() ? "Unknown" : tf4.getText();

            Employee ex = new Employee(name, age, salary, phone);
            al.add(ex);

            dispose(); // Dispose the current frame

            Frame2 f2 = new Frame2(al); // Create and set up the second frame
            f2.setVisible(true); // Make the second frame visible
        }
    }
}
