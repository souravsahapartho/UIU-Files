public class BankAccount {
    private String name;
    private String id;
    private double balance;
    private double lastTransaction;
    private String lastTransactionType;

    /***
     * Write necessary getter setter and constructors etc.- 5 marks
     */


    public void deposit(double amount) {
        if (amount > 0) {
            this.balance += amount;
            this.lastTransaction = amount;
            this.lastTransactionType = "Deposit";
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            this.balance -= amount;
            this.lastTransaction = amount;
            this.lastTransactionType = "Withdraw";
        }
    }
}
