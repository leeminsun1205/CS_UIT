import pandas as pd

# Đọc dữ liệu từ file CSV
train_df = pd.read_csv('test_dataset.csv')

# Kiểm tra phân phối nhãn hiện tại
print("Training class distribution:")
print(train_df['Label'].value_counts())

# Số lượng mẫu cần giữ lại cho mỗi nhãn
n_samples_per_label = 98

# Lấy mẫu ngẫu nhiên 400 mẫu từ mỗi nhãn
balanced_df = train_df.groupby('Label').apply(lambda x: x.sample(n=n_samples_per_label, random_state=42)).reset_index(drop=True)

# Xáo trộn lại tập dữ liệu
balanced_df = balanced_df.sample(frac=1, random_state=42).reset_index(drop=True)

# Kiểm tra lại phân phối nhãn sau khi lấy mẫu
print("Training class distribution after undersampling and shuffling:")
print(balanced_df['Label'].value_counts())

# Xuất tập dữ liệu mới ra file CSV
balanced_df.to_csv('test_dataset.csv', index=False)

print("Balanced and shuffled dataset has been saved successfully.")
