package class_8;
//Concrete class
public class Bird extends Animal implements Flyable,Floatable{

    Bird(String color, String name){
        super(color,name);
    }

    @Override
    public void makeSound(){
        System.out.println("Chirp");
    }

    @Override
    public void fly() {
        System.out.println("Bird is flying");
    }

    @Override
    public void floating() {

    }
}
