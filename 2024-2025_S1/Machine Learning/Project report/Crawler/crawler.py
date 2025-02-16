import requests
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

# Tạo thư mục lưu ảnh
# name_dir = "Mercedes-Benz"
name_dir = "OT1"
os.makedirs(name_dir, exist_ok=True)
# base_url = "https://www.gettyimages.com/photos/mitsubishi?page="
# page_start = 2
# page_end = 4
# websites = [f"{base_url}{page}" for page in range(page_start, page_end + 1)]
# Danh sách các trang web
websites = [
    'https://oto.com.vn/bang-gia-xe-o-to-nissan-moi-nhat',
    'https://vi.pngtree.com/free-backgrounds-photos/xe-nissan-pictures',
    'https://www.pexels.com/vi-vn/tim-kiem/nissan%20gtr/',
    'https://www.pexels.com/vi-vn/tim-kiem/nissan%20gtr/',
    'https://anycar.vn/tin-tuc/gia-xe-nissan/',
    'https://oto.com.vn/bang-gia-xe-o-to-nissan-kicks-moi-nhat',
    'https://thanhnien.vn/lo-anh-xe-nissan-7-cho-canh-tranh-toyota-fortuner-1851266353.htm',
    'https://daily-nissan.com/san-pham/nissan-navara-el/',
    'https://nissanphamvandong.net/gia-xe-nissan-navara/',
    'https://nissanphamvandong.net/gia-xe-nissan-navara/',
    'https://dailymuabanxe.net/nissan-era/',
    'https://www.winauto.vn/gia-xe-oto/nissan/',
    'https://nissanclub.com.vn/san-pham/nissan-terra',
    'https://daily-nissan.com/san-pham/nissan-almera-vl/',
    'https://nissanphamvandong.net/gia-xe-nissan-patrol/',
    'https://www.peugeotthanhxuan.vn/gia-xe-nissan-almera/',
    'https://nissanclub.com.vn/san-pham/sunny',
    'https://oto-nissandanang.com/san-pham/nissan-kicks-e-power-dong-xe-thuan-dien-duoc-doc-quye-ve-cong-nghe-110.html',
    'https://www.winauto.vn/nissan-almera-2025/',
    'https://nissanhanoi3s.com/san-pham/nissan-navara-2-cau/',
    'https://carpla.vn/blog/bang-gia-xe-nissan'
    'https://oto.com.vn/bang-gia-xe-o-to-isuzu-moi-nhat',
    'https://oto.com.vn/bang-gia-xe-o-to-isuzu-mu-x-moi-nhat',
    'https://bonbanh.com/gia-xe-oto-isuzu',
    'https://isuzumiendong.com/xe-isuzu-7-cho/',
    'https://www.peugeotthanhxuan.vn/gia-xe-isuzu-mu-x/',
    'https://isuzuviethai.com/xe-isuzu/isuzu-mu-x-b7-mau-trang/',
    'https://isuzuhadong.vn/xe-7-cho-mux-2/isuzu-mu-x-b7-1-9l-4x2-mt/',
    'https://carpla.vn/blog/bang-gia-xe-isuzu',
    'https://www.winauto.vn/gia-xe-oto-chevrolet/',
    'https://anycar.vn/gia-xe-o-to-chevrolet-t194714.html',
    'https://katavina.com/tin-xe/gia-xe-chevrolet-7-cho.html?srsltid=AfmBOopVi-QgS4gCJgbgfqXPf2BuvCONBJjXEfkCqTkFsgE6qlsebdo3',
    'https://chevroletnewway.com.vn/hinh-anh-thuc-te-chevrolet-aveo',
    'https://danchoioto.vn/gia-xe-chevrolet/',
    'https://dailymuabanxe.net/chevrolet-tahoe/',
    'https://oto365.net/gia-xe-oto-chevrolet'
]

# Header giả lập trình duyệt
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.81 Safari/537.36"
}

# Ngưỡng kích thước tối thiểu của ảnh (bỏ qua ảnh nhỏ hơn kích thước này)
MIN_WIDTH = 224
MIN_HEIGHT = 224

# Các từ khóa loại trừ không cần tải
EXCLUDED_KEYWORDS = ["icon", "placeholder", "thumb", "logo"] 

# Biến toàn cục theo dõi chỉ số ảnh
global_img_idx = 1028

# Hàm tải ảnh
def download_image(img_url, folder=name_dir, img_idx=1):
    try:
        # Tên file theo định dạng yêu cầu
        img_name = f"22521027-22520195-22521060.{folder}.{img_idx}.jpg"
        # Tải ảnh
        img_data = requests.get(img_url, headers=headers, timeout=10).content
        # Lưu ảnh
        file_path = os.path.join(folder, img_name)
        with open(file_path, "wb") as f:
            f.write(img_data)
        print(f"[+] Lưu thành công: {file_path}")
    except Exception as e:
        print(f"[-] Lỗi khi tải {img_url}: {e}")

# Hàm kiểm tra kích thước ảnh
def is_valid_image(img):
    try:
        width = int(img.get_attribute("naturalWidth"))
        height = int(img.get_attribute("naturalHeight"))
        if width >= MIN_WIDTH and height >= MIN_HEIGHT:
            return True
        else:
            print(f"[-] Bỏ qua ảnh kích thước nhỏ: {width}x{height}")
            return False
    except:
        # Nếu không lấy được kích thước, bỏ qua ảnh này
        return False

# Hàm kiểm tra từ khóa loại trừ
def contains_excluded_keywords(img_url):
    for keyword in EXCLUDED_KEYWORDS:
        if keyword in img_url:
            print(f"[-] Bỏ qua ảnh không cần thiết: {img_url}")
            return True
    return False

# Hàm crawl sử dụng Selenium
def crawl_with_selenium(url):
    global global_img_idx
    print(f"Đang crawl trang với Selenium: {url}")
    try:
        # Khởi tạo trình duyệt
        driver = webdriver.Chrome()  # Đảm bảo đã cài đặt ChromeDriver
        driver.get(url)
        time.sleep(5)  # Đợi trang tải hoàn toàn

        # Lấy tất cả thẻ ảnh
        images = driver.find_elements(By.TAG_NAME, "img")
        print(f"Đã tìm thấy {len(images)} ảnh trong trang.")


        # Tải và lưu từng ảnh
        for img in images:
            img_url = img.get_attribute("src")
            if img_url and img_url.startswith("http"):
                # Kiểm tra từ khóa loại trừ và kích thước ảnh
                if not contains_excluded_keywords(img_url) and is_valid_image(img):
                    download_image(img_url, folder=name_dir, img_idx=global_img_idx)
                    global_img_idx += 1  # Tăng chỉ số toàn cục sau mỗi ảnh
                else:
                    print(f"[-] Ảnh bị loại bỏ: {img_url}")

    except Exception as e:
        print(f"[-] Lỗi khi crawl với Selenium: {e}")
    finally:
        # Đóng trình duyệt
        driver.quit()

# Kiểm tra và crawl từng trang
for site in websites:
    try:
        print(f"Đang kiểm tra trang: {site}")
        crawl_with_selenium(site)  # Sử dụng Selenium cho trang này
    except Exception as e:
        print(f"[-] Lỗi không xác định: {e}")
