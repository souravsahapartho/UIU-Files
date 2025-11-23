package class_8.problem5;

public class BanglaCar {
    public static void main(String[] args) {
        Product product = new CentralLocking("Central Locking System");
        Product product2 = new GearLocking("Gear Locking System");

        Car car = new BMW(product, "BMW X5 Model");
        car.produceProduct();
        car.assemble();
        car.printDetails();

        System.out.println();

        car = new BMW(product2, "BMW X5 Model");
        car.produceProduct();
        car.assemble();
        car.printDetails();

        System.out.println();

        car = new Mercedes(product, "Mercedes GLS Model");
        car.produceProduct();
        car.assemble();
        car.printDetails();

        System.out.println();

        car = new Mercedes(product2, "Mercedes GLS Model");
        car.produceProduct();
        car.assemble();
        car.printDetails();

    }
}
