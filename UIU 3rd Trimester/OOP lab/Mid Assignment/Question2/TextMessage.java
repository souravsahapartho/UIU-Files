package Question2;

public class TextMessage extends Message implements Sendable {
    private String content;

    public void setContent(String content) {
        this.content = content;
    }

    public TextMessage(String sender, String receiver, String content, String timestamp) {
        super(sender, receiver);
        this.setContent(content);
        super.setTimestamp(timestamp);
    }

    @Override
    public String get_details() {
        return super.get_details() + " Content: " + content;
    }

    @Override
    public void prepare() {
        System.out.println("Preparing text message for sendind...");

    }

    @Override
    public void deliver() {
        System.out.println("Delivering text message to the recipient " + receiver);

    }

    @Override
    public void send() {
        System.out.println(this.get_details());
        this.prepare();
        this.deliver();
    }

}
