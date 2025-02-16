import os
from PIL import Image

def resize_images(folder_path, target_size=(224, 224)):
    """
    Resize images smaller than the target size to the target size and delete the original file safely.

    Args:
        folder_path (str): Path to the folder containing images.
        target_size (tuple): Target size (width, height) to resize images.
    """
    if not os.path.exists(folder_path):
        print("Thư mục không tồn tại.")
        return

    # Duyệt qua tất cả các file trong thư mục
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.lower().endswith((".jpg", ".jpeg", ".png", ".webp")):
                file_path = os.path.join(root, file)
                try:
                    with Image.open(file_path) as img:
                        # Kiểm tra kích thước ảnh hiện tại
                        if img.size[0] < target_size[0] or img.size[1] < target_size[1]:
                            # Resize ảnh nhỏ hơn target_size
                            resized_img = img.resize(target_size, Image.ANTIALIAS)

                            # Lưu file mới với cùng tên
                            resized_img.save(file_path, format="JPEG")
                            print(f"Đã resize và lưu: {file_path}")
                        else:
                            print(f"Bỏ qua: {file_path} (đã lớn hơn hoặc bằng {target_size})")
                except Exception as e:
                    print(f"Lỗi khi xử lý {file_path}: {e}")

# Đường dẫn thư mục cần resize
folder_path = "D:\Crawler\Mazda"  # Thay bằng đường dẫn thư mục của bạn
resize_images(folder_path)
