from flask import Flask, request, jsonify, render_template
import joblib
import pandas as pd

app = Flask(__name__)

# Load the pre-trained model and label encoders
model = joblib.load('best_rf_model.pkl')
le_gender = joblib.load('le_gender.pkl')
le_worktime = joblib.load('le_worktime.pkl')
le_foodhabit = joblib.load('le_foodhabit.pkl')
le_electronichabit = joblib.load('le_electronichabit.pkl')
le_noise = joblib.load('le_noise.pkl')
le_label = joblib.load('le_label.pkl')

def get_advice(prediction):
    advice_dict = {
        'Bình thường': 'Tình trạng giấc ngủ của bạn có vẻ bình thường. Hãy duy trì lối sống lành mạnh.',
        'Mất ngủ nhẹ': 'Bạn bị mất ngủ nhẹ. Hãy cân nhắc giảm thời gian sử dụng thiết bị điện tử trước khi đi ngủ và tránh dùng caffeine vào buổi tối.',
        'Có nguy cơ rối loạn giấc ngủ': 'Bạn có nguy cơ mắc rối loạn giấc ngủ. Nên tham khảo ý kiến bác sĩ.',
        'Rối loạn giấc ngủ': 'Bạn bị rối loạn giấc ngủ. Nên tham khảo ý kiến chuyên gia y tế.',
        'Hội chứng ngưng thở khi ngủ': 'Bạn bị ngưng thở khi ngủ. Hãy tham khảo ý kiến bác sĩ để được chẩn đoán và điều trị.',
        'Chứng ngủ rũ': 'Bạn bị chứng ngủ rũ. Nên tham khảo ý kiến chuyên gia y tế.',
        'Giấc ngủ tốt': 'Chất lượng giấc ngủ của bạn tốt. Hãy duy trì các thói quen tốt này!'
    }
    return advice_dict.get(prediction, "Không có lời khuyên nào cho tình trạng này.")

def translate_label(label):
    translation_dict = {
        'Normal': 'Bình thường',
        'Mild Insomnia': 'Mất ngủ nhẹ',
        'Risk of Disorder': 'Có nguy cơ rối loạn giấc ngủ',
        'Sleep Disorder': 'Rối loạn giấc ngủ',
        'Sleep Apnea': 'Hội chứng ngưng thở khi ngủ',
        'Narcolepsy': 'Chứng ngủ rũ',
        'Good Sleep': 'Giấc ngủ tốt'
    }
    return translation_dict.get(label, label)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    data = request.form
    features = pd.DataFrame({
        'Gender': [le_gender.transform([data['Gender']])[0]],
        'Age': [int(data['Age'])],
        'BMI': [float(data['BMI'])],
        'BP': [int(data['BP'])],
        'HR': [int(data['HR'])],
        'WorkTime': [le_worktime.transform([data['WorkTime']])[0]],
        'Activity': [int(data['Activity'])],
        'Stress': [int(data['Stress'])],
        'FoodHabit': [le_foodhabit.transform([data['FoodHabit']])[0]],
        'ElectronicHabit': [le_electronichabit.transform([data['ElectronicHabit']])[0]],
        'Temp': [int(data['Temp'])],
        'Noise': [le_noise.transform([data['Noise']])[0]],
        'SleepDuration': [int(data['SleepDuration'])],
        'SleepStart': [int(data['SleepStart'])],
        'SleepQuality': [int(data['SleepQuality'])]
    })
    
    prediction = model.predict(features)[0]
    prediction_label = le_label.inverse_transform([prediction])[0]
    translated_label = translate_label(prediction_label)
    advice = get_advice(translated_label)

    return render_template('result.html', prediction=translated_label, advice=advice)

if __name__ == "__main__":
    app.run(debug=True)
