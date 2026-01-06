CREATE TABLE library_books (
    book_id VARCHAR(20) PRIMARY KEY,
    book_title VARCHAR(40) NOT NULL,
    author VARCHAR(30),
    price DECIMAL(8,2)
);

CREATE TABLE members (
    member_id INT PRIMARY KEY,
    member_name VARCHAR(30),
    membership_type VARCHAR(20),
    borrowed_book VARCHAR(20),
    CONSTRAINT fk_borrowed_book FOREIGN KEY (borrowed_book) REFERENCES library_books(book_id)
);

INSERT INTO library_books (book_id, book_title, author, price) VALUES
('B101', 'Database Systems', 'Navathe', 500.00),
('B102', 'Clean Code', 'Robert Martin', 700.00),
('B103', 'Algorithms', 'CLRS', 900.00);

INSERT INTO members (member_id, member_name, membership_type, borrowed_book) VALUES
(1, 'Rahim', 'Regular', 'B101'),
(2, 'Karim', 'Premium', 'B103');

ALTER TABLE members
ADD COLUMN email VARCHAR(40);

ALTER TABLE library_books
ADD COLUMN published_year INT,
ADD COLUMN category VARCHAR(20);

ALTER TABLE library_books
MODIFY COLUMN price DECIMAL(10,2);

ALTER TABLE members
DROP COLUMN membership_type;

ALTER TABLE members
CHANGE COLUMN member_name full_name VARCHAR(30);

ALTER TABLE library_books
RENAME TO books_archive;

DROP TABLE members;
