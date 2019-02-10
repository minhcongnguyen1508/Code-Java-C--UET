lab06.php

Gui mail nop report
mail: th.dbms@gmail.com
title: Lab6_MaSV_HoTen

file: Lab06_MaSV_HoTen.txt
Deadline: 22h - 2/11/2018


#Câu 1
# 1-a:
#B1 Coppy mysql làm 2 file và đổi tên thành Mysql_Master và Mysql_Slave
	#Thay đổi file my.ini ở cả 2 thư mục
	#Thay đổi port Master: port = 3306, server-id = 1, log-bin = mysql-bin
	#Thay đổi port Slave: port = 3307, server-id = 2
#B2 Bật server
#Bật server master ở file ./Mysql_Master/bin (Sử dụng thêm option --log-bin để cho phép ghi log trên master)
mysqld -u root -P 3306 --log-bin --console 
#Đăng nhập
mysql -u root -p -P 3306

#B3 dump dữ liệu master ra để ghi vào slave để đảm bảo master và slave có cùng cơ sở dữ liệu
#Sử dụng tham số --master--data = 2
mysqldump --flush-logs --all-database --master-data=2 -u root -p > C:/Users/Cong/Desktop/sakila-backup.sql
#B4 Thiết lập tài khoản trên Master để Slave có thể truy cập vào
	GRANT REPLICATION SLAVE ON *.* TO 'slavehost'@'localhost' IDENTIFIED BY '15082907'; 
#B5 Lấy thông tin file log
	show master status;
	UNLOCK TABLES;
	QUIT;

#B6 --Làm việc trên slave
#import data vào slave, có thể drop data base sakila cũ đi để đảm bảo slave và master có cùng CSDL
#import database vua dump ra tu master
#Bật server slave ở file ./Mysql_Slave/bin
mysqld -u root -P 3307 --console
#Đăng nhập  
mysql -u root -P 3307
# đăng nhập
mysql -u root - p -P 3307
#drop sakila trong slave 
drop database if exists sakila;
Quit;
#import dulieu
mysql -u root -p -P 3307 < C:/Users/Cong/Desktop/sakila-backup.sql
#Đăng nhập  
mysql -u root -P 3307

#B7 Cấu hình bên slave, Từ Slave thay đổi cấu hình để phù hợp với master
CHANGE MASTER TO MASTER_HOST='127.0.0.1',
MASTER_USER='slavehost',
MASTER_PASSWORD='15082907',
MASTER_LOG_FILE='Cong-PC-bin.000036',
MASTER_LOG_POS=565;
#Trong đó, Master_host là địa chỉ host của master
#			Master_user, master_password có được từ bước 4 
#			Master_log_file, master_log_pos có được từ bước 5

FLUSH TABLES WITH READ LOCK;
SET GLOBAL READ_ONLY = ON;
// chỉ cho slave đọc
#B8 
	Start Slave;
#
#B9 Thực hiện các lệnh update, insert bên master và kiểm tra lại trên slave bằng lệch select
#Ở master
update film_text
set title = 'hallow'
where film_id = 2;
# Ở slave
Select * from film_text
where film_id = 2;
# 1-b. Tắt Slave và cập nhật dữ liệu trên master thì sau đó khi bật Slave lên dữ liệu sẽ được cập nhật lại bên máy Slave. Vì đã có file Log và position #của Master
#Bật Slave 
#1-c. Dữ liệu tự sinh là giống nhau chỉ khác thời điểm cập nhật lại ở Slave là khi master thay đổi thì tới khi Slave bật lên mới được cập nhật.

#Câu 2:
#B1: shut down cấu hình và server của master & slave
#B2: Mở file ./Mysql_Slave/bin
# Thay đổi file my.ini
Thêm vào ở đoạn
[mysqld]
replicate-do-db=sakila
#B3 đăng nhập lại vào master và slave như ở câu 1
#B4 Thực hiện update thử ở slave CSDL khác.
#Ở master
create database newdata;
use newdata
create table name(id INT, name VARCHAR(30));
#B5 Thực hiện Kiểm tra ở slave.

# Câu 3:
#B1: shut down cấu hình và server của master & slave

# Bật server slave(Slave trở thành master ta bậtt --log-bin cho slave)
mysqld -u root -P 3307 --log-bin --console
# Bật server master
mysqld -u root -P 3306 --log-bin --console
# đăng nhập
mysql -u root -p -P 3307

mysql -u root -p -P 3306

#Thực hiện lại như ở câu 1 nhưng thêm master_port = 3307 
CREATE USER 'slavehost'@'localhost' IDENTIFIED BY '15082907';
GRANT REPLICATION SLAVE ON *.* TO 'slavehost'@'localhost';

CHANGE MASTER TO MASTER_HOST = 'localhost',
	MASTER_PORT = 3307,
	MASTER_USER = 'Slavehost',
	MASTER_PASSWORD = '15082907',
	MASTER_LOG_FILE = 'mysql-bin.000036',
	MASTER_LOG_POS = 44913903;

-- Test