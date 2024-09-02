import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import schedule
import time

# 配置您的電子郵件帳戶信息
email_address = "jzhu7926@gmail.com"
email_password = "xyz12345678"
recipient_email = "chujinkuan@gmail.com"

def send_email():
    # 建立郵件內容
    msg = MIMEMultipart()
    msg['From'] = email_address
    msg['To'] = recipient_email
    msg['Subject'] = "每日報告"

    # 這裡是您每日報告的內容
    body = "這是您的每日報告內容。"
    msg.attach(MIMEText(body, 'plain'))

    # 設置 SMTP 伺服器並發送郵件
    try:
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login(email_address, email_password)
        text = msg.as_string()
        server.sendmail(email_address, recipient_email, text)
        server.quit()
        print("郵件已成功發送")
    except Exception as e:
        print(f"郵件發送失敗: {e}")

# 定義每日發送時間
schedule.every().day.at("11:36").do(send_email)

# 持續運行以保持排程
while True:
    schedule.run_pending()
    time.sleep(1)
