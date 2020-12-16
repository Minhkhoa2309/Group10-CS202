***#Group10-CS202-19APCS1***

#Võ Khương Duy
#19125087

#Nguyễn Hoàng Hiếu
#19125091

#Tạ Ngọc Minh Khoa
#19125100

#Phạm Thiên Long
#19125104



+ cPosition, cPlayer, cLevel, cConsole, 
+ cObstacle, cTruck, cCar, cBird, cOneRow, cRows,cDinosaur
+ cMap
+ cGame

+ Player, Bird, Dinosaur, Car, Truck vẽ
+ Map vẽ và xử lí khung chơi game
+ Game vẽ và xử lí menu, save, load file

+ OneRow chứa toàn bộ Obstacle của một làn đường
+ Rows chứa toàn bộ OneRow của một màn
+ Level xử lí thông số như bao nhiêu Obstacle, tốc độ nhanh chậm, số làn của một màn
+ Console xử lí console, di chuyển trỏ chuột tới vị trí x-y nhất định
+ Position là tọa độ trên console



Hiếu: newGame(), continueGame(), loading(), toggleMute(), toggleHard()

Long: getAllFilename(), loadGameMenu(), saveGameMenu(), gameOver()

Duy: gameSetting(), menu(), continueMenu(), togglePauseGame()
