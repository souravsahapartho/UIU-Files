package class_8;

public class AbstractTest {
    public static void main(String[] args) {
        Animal t = new Tiger("Orange", "Royan; Bengal Tiger");
        Animal b = new Bird("brown","Doel");

        t.eat();
        t.makeSound();
        ((Tiger)t).hello();

        b.eat();
        b.makeSound();
    }
}
