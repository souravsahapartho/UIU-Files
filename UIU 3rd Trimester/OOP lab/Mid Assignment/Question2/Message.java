package Question2;

public abstract class Message {
    public String sender;
    private String timestamp;
    public String receiver;

    public Message(String sender, String receiver) {
        this.sender = sender;
        this.receiver = receiver;


    }

    public void setTimestamp(String timestamp) {
        this.timestamp = timestamp;
    }

    public String get_details() {
        return
                "Sender:" + sender +
                        ", Timestamp: '" + timestamp +
                        ", Receiver: " + receiver + ",";
    }

    public void send() {
    }
}
