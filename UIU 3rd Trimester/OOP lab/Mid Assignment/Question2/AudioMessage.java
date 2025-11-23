package Question2;

import java.security.spec.RSAOtherPrimeInfo;

public class AudioMessage extends Message implements Sendable{
    private String audio_url;

    public void setAudio_url(String audio_url) {
        this.audio_url = audio_url;
    }

    public AudioMessage(String sender, String receiver,String audio,String timestamp) {
        super(sender, receiver);
        this.setAudio_url(audio);
        super.setTimestamp(timestamp);
    }



    @Override
    public String get_details() {
        return super.get_details()+" Audio URL: "+audio_url;
    }

    @Override
    public void prepare() {
        System.out.println("Preparing audio message for sending...");

    }

    @Override
    public void deliver() {
        System.out.println("Delivering audio message for recipient "+receiver);

    }

    public void send() {
        System.out.println(this.get_details());
        this.prepare();
        this.deliver();
    }

    
}
