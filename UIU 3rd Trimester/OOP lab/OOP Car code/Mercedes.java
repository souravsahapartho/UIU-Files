package class_8.problem5;

public class Mercedes extends Car{
    public Mercedes(Product p, String carType) {
        super(p, carType);
    }

    @Override
    public void assemble() {
        System.out.println("Assembling "+p.getProductName()+" for "+this.carType);
    }

    @Override
    public void produceProduct() {
        p.produce();
        System.out.println("Modifying product "+p.getProductName()+" according to "+ this.carType);
    }
}
