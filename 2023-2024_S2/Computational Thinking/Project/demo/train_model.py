import pandas as pd
import numpy as np
from sklearn.model_selection import KFold, RandomizedSearchCV
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, accuracy_score
import matplotlib.pyplot as plt
import joblib
from scipy.stats import randint as sp_randint
from imblearn.over_sampling import SMOTE

# Đọc dữ liệu từ các file CSV
train_df = pd.read_csv('train_dataset.csv')
test_df = pd.read_csv('test_dataset.csv')

# Tiền xử lý dữ liệu
def preprocess_data(df):
    le_gender = LabelEncoder()
    le_worktime = LabelEncoder()
    le_foodhabit = LabelEncoder()
    le_electronichabit = LabelEncoder()
    le_noise = LabelEncoder()
    le_label = LabelEncoder()
    
    df['Gender'] = le_gender.fit_transform(df['Gender'])
    df['WorkTime'] = le_worktime.fit_transform(df['WorkTime'])
    df['FoodHabit'] = le_foodhabit.fit_transform(df['FoodHabit'])
    df['ElectronicHabit'] = le_electronichabit.fit_transform(df['ElectronicHabit'])
    df['Noise'] = le_noise.fit_transform(df['Noise'])
    df['Label'] = le_label.fit_transform(df['Label'])
    
    joblib.dump(le_gender, 'le_gender.pkl')
    joblib.dump(le_worktime, 'le_worktime.pkl')
    joblib.dump(le_foodhabit, 'le_foodhabit.pkl')
    joblib.dump(le_electronichabit, 'le_electronichabit.pkl')
    joblib.dump(le_noise, 'le_noise.pkl')
    joblib.dump(le_label, 'le_label.pkl')
    
    return df, le_label

train_df, le_label = preprocess_data(train_df)
test_df, _ = preprocess_data(test_df)

X_train = train_df.drop('Label', axis=1)
y_train = train_df['Label']
X_test = test_df.drop('Label', axis=1)
y_test = test_df['Label']

# # Áp dụng SMOTE để xử lý mất cân bằng
# smote = SMOTE(random_state=42)
# X_train_smote, y_train_smote = smote.fit_resample(X_train, y_train)

# Thiết lập KFold
kf = KFold(n_splits=5, shuffle=True, random_state=3107)

# Tạo mô hình Random Forest và thiết lập RandomizedSearchCV
rf = RandomForestClassifier(random_state=3107)
param_dist = {
    'n_estimators': sp_randint(200, 500),
    'max_features': ['auto', 'sqrt', 'log2'],
    'max_depth': [None] + list(np.arange(10, 20)),
    'min_samples_split': sp_randint(2, 8),
    'min_samples_leaf': sp_randint(2, 8),
    'bootstrap': [True, False]
}

random_search = RandomizedSearchCV(rf, param_distributions=param_dist, 
                                   n_iter=50, scoring='f1_weighted', 
                                   cv=kf, random_state=3107, n_jobs=-1, verbose=2)

# Huấn luyện mô hình
random_search.fit(X_train, y_train)

# Dự đoán trên tập test
y_pred = random_search.predict(X_test)

# Đánh giá mô hình
print("Best parameters found: ", random_search.best_params_)
print("Accuracy:", accuracy_score(y_test, y_pred))
print("Classification Report:")
print(classification_report(y_test, y_pred, target_names=le_label.classes_))

# Hiển thị tầm quan trọng của các đặc trưng
importance = random_search.best_estimator_.feature_importances_
feature_names = X_train.columns
feature_importance = pd.DataFrame({'Feature': feature_names, 'Importance': importance})
feature_importance = feature_importance.sort_values(by='Importance', ascending=False)

plt.figure(figsize=(10, 8))
plt.barh(feature_importance['Feature'], feature_importance['Importance'])
plt.gca().invert_yaxis()
plt.title('Feature Importance - Random Forest')
plt.show()

# Lưu mô hình
joblib.dump(random_search.best_estimator_, 'best_rf_model.pkl')
print("Model has been saved successfully.")
