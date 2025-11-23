package class_8.problem5;

public class CentralLocking implements Product{
    String productName;

    public CentralLocking(String productName) {
        this.productName = productName;
    }

    @Override
    public String getProductName() {
        return productName;
    }

    @Override
    public void produce() {
        System.out.println("Producing Central Locking System");
    }
}
