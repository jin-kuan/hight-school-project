import csv
file=open("data.csv",'r')
csvCursor=csv.DictReader(file)

for row in csvCursor:
    print(row['name'],row['score'])
file.close()