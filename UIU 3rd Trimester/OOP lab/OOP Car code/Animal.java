package class_8;

public abstract class Animal {
    String color;
    String name;

    public Animal(String color, String name) {
        this.color = color;
        this.name = name;
    }

    public void eat(){
        System.out.println("Animal is eating");
    }

    //abstract class may contain zero or more abstract methods
    public abstract void makeSound();

    public static void main(String[] args) {
        //Abstract classes cannot be instantiated(cannot create objects).
//        Animal a = new Animal("Orange","Tiger");
    }
}
