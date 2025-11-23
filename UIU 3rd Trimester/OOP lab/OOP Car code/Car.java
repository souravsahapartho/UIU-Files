package class_8.problem5;

public abstract class Car {
    protected Product p;
    protected String carType;

    public Car(Product p, String carType) {
        this.p = p;
        this.carType = carType;
    }

    public abstract void assemble();

    public abstract void produceProduct();

    public void printDetails(){
        System.out.println("Car: "+carType+", Product: "+p.getProductName());
    }
}
