#1.
CREATE TABLE payment_log (payment_id SMALLINT, insert_date TIMESTAMP, update_date TIMESTAMP);
DELIMITER //
drop trigger if exists payment_update//
CREATE TRIGGER payment_update AFTER UPDATE ON payment FOR EACH ROW
BEGIN
	INSERT INTO payment_log(payment_id, insert_date, update_date) VALUES(old.payment_id, null, now());
END//
CREATE TRIGGER payment_update AFTER INSERT ON payment FOR EACH ROW
BEGIN
	INSERT INTO payment_log(payment_id, insert_date, update_date) VALUES(old.payment_id, now(), null);
END//
DELIMITER ; 

#2.
DELIMITER //
ALTER TABLE inventory ADD is_available BOOLEAN(false)//
drop trigger if exists inv_rentaldate//
CREATE TRIGGER inv_rentaldate AFTER update ON rental FOR EACH ROW
BEGIN
	IF(return_date = NULL)THEN UPDATE inventory
		SET is_available = false
        Where (old.inventory_id = new.inventory_id);
	ELSEIF
	(return_date != NULL)
	THEN UPDATE inventory
		SET is_available = true
		Where (old.inventory_id = new.inventory_id);
	END IF;
END//

CREATE TRIGGER inv_rentaldate1 AFTER insert ON rental FOR EACH ROW
begin
	update inventory
	set is_available = false
	where inventory_id = new.inventory_id;
end//
DELIMITER ;
insert into rental(rental_date, inventory_id, customer_id, staff_id) values(now(), 1, 1, 1);
update rental set return_date = now() where rental_id = 12321;


#3-OK
drop view if exists customer_list;
CREATE VIEW customer_list AS 
SELECT c.customer_id, a.address, a.phone, a.city_id 
FROM customer c
join address a on c.address_id = a.address_id;

update customer_list 
set address = 'xuan thuy', phone = '012321312312', city_id = 123
where customer_id = 1;

# VIEW cho phep truy van cap nhat, insert, nhung khong cho phep 
#Aggregate functions suchas MIN, MAX, SUM, AVG, COUNT, etc.
#DISTINCT Loai bo gia tri trung lap
#GROUP BY clause.
#HAVING clause.
#UNION - Ket hop 2 select  loai bo trung lap or UNION ALL - ket hop selecet ko loai bo trung lap clause. 
#Left join or outer j


#4
drop view if exists actor_list;
create view actor_list as
select a.actor_id, f.film_id from actor a
left join film_actor f on a.actor_id = f.actor_id;
#vi view khong LEFT JOIN dc de => luon nhung actor khong tham gia


#5THAM kHAO PHAN THAY BAO>! TRONG VIEW OF FILM> dấu :, dấu ;

drop view if exists sales_by_customer;
CREATE VIEW sales_by_customer AS 
select c.customer_id, CONCAT(c.first_name, ' ',c.last_name) AS customer, SUM(p.amount) AS total_sales
FROM payment AS p
JOIN customer c ON p.customer_id = c.customer_id
GROUP BY c.customer_id
ORDER BY total_sales DESC; 

#################################

Một thủ tục lưu trữ:
• chấp nhận tham số
• KHÔNG thể được sử dụng làm khối xây dựng trong truy vấn lớn hơn
• có thể chứa một số câu lệnh, vòng lặp, IF ELSE, v.v.
• có thể thực hiện các sửa đổi cho một hoặc nhiều bảng
• KHÔNG thể được sử dụng làm đích của câu lệnh INSERT, UPDATE hoặc DELETE.

Một view:
• KHÔNG chấp nhận các tham số
• có thể được sử dụng làm khối xây dựng trong truy vấn lớn hơn
• chỉ có thể chứa một truy vấn SELECT duy nhất
• KHÔNG thể thực hiện các sửa đổi đối với bất kỳ bảng nào
• nhưng có thể (đôi khi) được sử dụng làm đích của câu lệnh INSERT, UPDATE hoặc DELETE.