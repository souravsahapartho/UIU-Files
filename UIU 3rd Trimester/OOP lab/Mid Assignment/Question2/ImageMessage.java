package Question2;

public class ImageMessage extends Message implements Sendable {


    private String image_url;

    public void setImage_url(String image_url) {
        this.image_url = image_url;
    }

    public ImageMessage(String sender, String receiver, String image_url, String timestamp) {
        super(sender, receiver);
        this.setImage_url(image_url);
        super.setTimestamp(timestamp);
    }

    @Override
    public String get_details() {
        return super.get_details() + " Image URL: " + image_url;
    }

    @Override
    public void prepare() {
        System.out.println("Preparing image message for sending...");

    }

    @Override
    public void deliver() {
        System.out.println("Delivering image message for recipient " + receiver);


    }

    public void send() {
        System.out.println(this.get_details());
        this.prepare();
        this.deliver();
    }
}
