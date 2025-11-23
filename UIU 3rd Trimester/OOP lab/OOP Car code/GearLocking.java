package class_8.problem5;

public class GearLocking implements Product {
    String productName;

    public GearLocking(String productName) {
        this.productName = productName;
    }

    @Override
    public String getProductName() {
        return productName;
    }

    @Override
    public void produce() {
        System.out.println("Producing Gear Locking System");
    }
}
