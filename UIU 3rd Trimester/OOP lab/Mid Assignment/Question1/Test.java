package Question1;

import java.util.ArrayList;
import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        ArrayList<Employee> al = new ArrayList<>();
        System.out.print("Enter the amount of employees: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String name, id;
            int salary;
            name = sc.nextLine();
            id = sc.nextLine();
            salary = sc.nextInt();
            sc.nextLine();
            al.add(new Employee(name, id, salary));
        }

        int count = 0;
        int max = 0;
        for (Employee e : al) {
            if (e.salary >= 12000) count++;
            if (e.salary > max) max = e.salary;
        }

        System.out.println("Count: " + count);
        System.out.println("Max = " + max);

    }
}
