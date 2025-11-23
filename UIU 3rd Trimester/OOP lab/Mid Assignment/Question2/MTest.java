package Question2;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class MTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sender;
        System.out.print("Enter your name: ");
        sender = sc.nextLine();


        while (true) {

            String receiver;
            System.out.print("Enter the receiver's name: ");
            receiver = sc.nextLine();


            int type;
            System.out.println("Select your message type:\n1.Text Message\n2.Audio Message\n3.Image Message");

            type = sc.nextInt();
            sc.nextLine();

            //for generating timestamp
            LocalDateTime now = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mm:ss.n");
            String fTimestamp = now.format(formatter);

            Message m = null;

            if (type == 1) {
                String message;
                System.out.print("Enter your text message: ");
                message = sc.nextLine();
                m = new TextMessage(sender, receiver, message, fTimestamp);
            } else if (type == 2) {
                String audio;
                System.out.print("Enter your audio url: ");
                audio = sc.nextLine();
                m = new AudioMessage(sender, receiver, audio, fTimestamp);
            } else if (type == 3) {
                String image;
                System.out.print("Enter your image url: ");
                image = sc.nextLine();
                m = new AudioMessage(sender, receiver, image, fTimestamp);

            }
            if (!(m == null))
                m.send();

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {

            }
            System.out.println("\nMessage delivered✔️");

            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {

            }
            System.out.println("\n\nDo you want to send another message?\n1.Yes\n2.NO");
            int x = sc.nextInt();
            sc.nextLine();
            if (x == 2) break;
        }

    }
}
