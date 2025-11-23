package class_8;

public class Tiger extends Animal{

    public Tiger(String color, String name) {
        super(color, name);
    }

    @Override
    public void makeSound() {
        System.out.println("Roar");
    }

    public void hello(){
        System.out.println("Tiger says hello");
    }
}
