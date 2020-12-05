# Group10-CS202-19APCS1

Võ Khương Duy
19125087

Nguyễn Hoàng Hiếu
19125091

Tạ Ngọc Minh Khoa
19125100

Phạm Thiên Long
19125104




+ cPosition, cPlayer, cLevel, cConsole, 
+ cObstacle, cTruck, cCar, cBird, cOneRow, cRows,cDinosaur
+ cMap
+ cGame

chủ yếu là thg Player, Truck, Car, Bird, Dinosaur phải ngồi kiếm cách vẽ
Map với Game thì nó làm khá nhiều việc

tổng hợp lại là:
+ Player, Bird, Dinosaur, Car, Truck phải ngồi vẽ
+ Map vẽ và xử lí khung chơi game
+ Game vẽ và xử lí menu, save, load file

+ OneRow thì chứa toàn bộ Obstacle của một làn đường
+ Rows chứa toàn bộ OneRow của một màn
+ Level thì chỉ là mấy thông số như bao nhiêu Obstacle, tốc độ nhanh chậm, số làn của một màn
+ Console thì xử lí console, di chuyển trỏ chuột tới vị trí x-y nhất định
+ Position chỉ là tọa độ