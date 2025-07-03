# Thư viện tĩnh (Static libarry) DHT11 cho Raspberry Pi 

Đây là thư viện đơn giản để đọc dữ liệu từ cảm biến **DHT11** (nhiệt độ và độ ẩm) sử dụng Raspberry
và thư viện "wiringPi".
# Cấu trúc thư mục 
 dht11.h // Header khia báo các hàm DHT11
 dht11.c // File cài đặt thư viện DHT11
 main.c // Chương trình mẫu sử dụng thư viện 
# Yêu cầu phần cứng 
 Modul Raspberry Pi
 Cảm biến DHT11
 Kết nối:
  DATA của DHT11 -> GPIO4 (Physical pin 7)
  GND -> GND
  VCC -> 3.3V
# Cách biên dịch 
 Bước 1: Biên dịch file thư viện 
   gcc -c dht11.c -o dht11.o
 Bước 2: Tạo thư viện tĩnh
   ar rc libdht11.a dht11.o
 Bước 3: Biên dịch chương trình chính 
   gcc main.c -L. -ldht11 -o a -lwiringPi
 Bước 4: Run chương trình 
   ./a
# Kết quả mong muốn 
  Nhiệt độ: 30°C, Độ ẩm: 73%
# Ngoài ra bạn có thể biên dịch nó thành thư viện động để sử dụng nhiều lần và tiết kiệm bộ nhớ 
 Bước 1: Biên dịch file thư viện 
   gcc -fPIC -c dht11.c -o dht11.o
 Bước 2: Tạo thư viện động 
   gcc -shared -o libdht11.so dht11.o
 Bước 3: Biên dịch chương trình chính 
   gcc main.c -L. -ldht11 -o a -lwiringPi
 Bước 4: khai báo đường dẫn thư viện trong danh sách thư viện liên kết động bằng cách:
 export LD_LIBRARY_PATH=:/path/to/library.so
 Bước 5: Run chương trình 
   ./a