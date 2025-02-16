import os

# Đường dẫn thư mục chứa các ảnh
folder_path = 'D:\Crawler\Others'

# Lấy danh sách tất cả các tệp trong thư mục
file_list = [f for f in os.listdir(folder_path) if f.endswith('.jpg')]

# Sắp xếp lại danh sách theo tên để đảm bảo thứ tự
file_list.sort()

# Số cố định cho tên tệp
fixed_number_1 = 22521027
fixed_number_2 = 22520195
fixed_number_3 = 22521060

# Đổi tên các ảnh
for idx, filename in enumerate(file_list, start=1):
    # Lấy tên thư mục cuối cùng từ folder_path
    folder_name = os.path.basename(folder_path)
    new_filename = f"{fixed_number_1}-{fixed_number_2}-{fixed_number_3}.{folder_name}.{idx}.jpg"
    old_file_path = os.path.join(folder_path, filename)
    new_file_path = os.path.join(folder_path, new_filename)
    os.rename(old_file_path, new_file_path)

    print(f"Đã đổi tên: {old_file_path} -> {new_file_path}")
