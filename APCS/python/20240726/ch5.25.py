import csv

header = ['name', 'address', 'tel', 'email', 'age']
data = [['Sean', '123, Oak Street, Taipei', '02-9876-5432', 'sean@gmail.com', 40],
        ['Amy', '456, Park Avenue, Taichung', '04-8877-6655', 'amy@gmail.com', 30],
        ['David', '789 First Road Tainan', '06-654-3210', 'david@gmail.com', 25]]

file = open('contact.csv', 'w')
csvCursor = csv.writer(file)
csvCursor.writerow(header)
for d in data:
    csvCursor.writerow(d)
file.close()
print('聯絡人輸出至contact.csv')
