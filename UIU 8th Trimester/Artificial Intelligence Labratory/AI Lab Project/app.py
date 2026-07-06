import gradio as gr
import pickle
import re


model = pickle.load(open("emotion_model.pkl", "rb"))
vectorizer = pickle.load(open("tfidf.pkl", "rb"))
encoder = pickle.load(open("label_encoder.pkl", "rb"))



def clean_text(text):
    text = str(text)
    text = text.lower()

    text = re.sub(r"http\S+", "", text)
    text = re.sub(r"[^a-z ]", "", text)
    text = re.sub(r"\s+", " ", text)

    return text.strip()


def predict_emotion(text):

    cleaned = clean_text(text)

    vector = vectorizer.transform([cleaned])

    prediction = model.predict(vector)[0]

    emotion = encoder.inverse_transform([prediction])[0]

    return f"Detected Emotion: {emotion}"



interface = gr.Interface(
    fn=predict_emotion,
    inputs=gr.Textbox(
        lines=4,
        placeholder="Type your text here..."
    ),
    outputs=gr.Textbox(
        label="Prediction"
    ),
    title="Emotion Detection",
    description="Enter text and predict emotion"
)

interface.launch()