import serial

ser = serial.Serial('COM3', 9600)  # 포트는 환경에 맞게 수정
print("시리얼 포트 연결됨")

while True:
    try:
        line = ser.readline().decode('utf-8').strip()
        temp, humi, heat = map(float, line.split(","))
        print(f"온도: {temp:.2f}°C | 습도: {humi:.2f}% | 열지수: {heat:.2f}°C")
    except Exception as e:
        print("에러:", e)