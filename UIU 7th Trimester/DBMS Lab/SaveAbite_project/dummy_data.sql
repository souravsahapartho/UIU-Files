-- SaveABite Dummy Data Seeding Script
USE saveabite;

-- 1. Ensure Zones exist (if not already seeded)
INSERT IGNORE INTO zones (id, zone_name) VALUES 
(1, 'Dhaka South'), 
(2, 'Dhaka North'), 
(3, 'Chittagong'), 
(4, 'Sylhet');

-- 2. Insert Users (Donors, Volunteers, and Normal Users)
-- Using plain text passwords for testing as requested
INSERT IGNORE INTO users (id, name, email, password, user_type, zone_id) VALUES
(2, 'Kacchi Bhai', 'kb@donor.com', 'pass123', 'donor', 1),
(3, 'Sultan Dine', 'sd@donor.com', 'pass123', 'donor', 2),
(4, 'Star Kabab', 'star@donor.com', 'pass123', 'donor', 1),
(5, 'Arif Ahmed', 'arif@vol.com', 'pass123', 'volunteer', 1),
(6, 'Sara Islam', 'sara@vol.com', 'pass123', 'volunteer', 2),
(7, 'Tanvir Hossain', 'tanvir@vol.com', 'pass123', 'volunteer', 3),
(8, 'Rahat Khan', 'rahat@user.com', 'pass123', 'user', 1),
(9, 'Maliha Zaman', 'maliha@user.com', 'pass123', 'user', 2),
(10, 'Nabil Rahman', 'nabil@user.com', 'pass123', 'user', 4),
(11, 'Foodie Cafe', 'cafe@donor.com', 'pass123', 'donor', 3);

-- 3. Insert Food Listings
-- statuses: Available, Claimed, In Transit, Delivered
INSERT IGNORE INTO food_listings (id, donor_id, food_details, quantity, status, pickup_deadline, otp_code) VALUES
(1, 2, 'Beef Kacchi - 20 Plates', '5kg', 'Available', '2026-01-20 22:00:00', '123456'),
(2, 3, 'Chicken Roast & Polao - 15 Servings', '4kg', 'Claimed', '2026-01-19 21:00:00', '654321'),
(3, 4, 'Mutton Biryani - 10 Servings', '3kg', 'Delivered', '2026-01-15 20:00:00', '111222'),
(4, 2, 'Assorted Kebabs', '2kg', 'In Transit', '2026-01-18 23:00:00', '333444'),
(5, 11, 'Vegetable Curry & Rice', '10 Servings', 'Available', '2026-01-21 19:00:00', '999888'),
(6, 3, 'Firni Dessert', '5kg', 'Delivered', '2026-01-14 22:00:00', '777666'),
(7, 4, 'Breakfast Box - Egg & Paratha', '30 Nos', 'Available', '2026-01-22 10:00:00', '555444'),
(8, 2, 'Mixed Fried Rice', '6kg', 'Claimed', '2026-01-18 20:00:00', '222888'),
(9, 11, 'Grilled Chicken', '12 Pieces', 'Delivered', '2026-01-12 21:00:00', '444555'),
(10, 3, 'Lentil Soup (Dal)', '10L', 'Available', '2026-01-20 20:00:00', '666111');

-- 4. Insert Deliveries (Missions)
INSERT IGNORE INTO deliveries (listing_id, volunteer_id, status, start_time, end_time) VALUES
(2, 5, 'Ongoing', '2026-01-18 10:00:00', NULL),
(3, 5, 'Completed', '2026-01-15 18:00:00', '2026-01-15 19:30:00'),
(4, 6, 'Ongoing', '2026-01-18 11:00:00', NULL),
(6, 6, 'Completed', '2026-01-14 20:00:00', '2026-01-14 21:15:00'),
(8, 7, 'Ongoing', '2026-01-18 12:00:00', NULL),
(9, 7, 'Completed', '2026-01-12 19:00:00', '2026-01-12 20:30:00');

-- 5. Insert Volunteer Stats (Points)
INSERT IGNORE INTO volunteer_stats (user_id, volunteer_name, green_points, total_rescues) VALUES
(5, 'Arif Ahmed', 50, 5),
(6, 'Sara Islam', 80, 8),
(7, 'Tanvir Hossain', 30, 3);

-- 6. Insert Monetary Donations
INSERT IGNORE INTO monetary_donations (user_id, amount, payment_method, transaction_id) VALUES
(8, 500.00, 'BKash', 'TXN789456'),
(9, 1200.00, 'Nagad', 'TXN123456'),
(10, 250.00, 'BKash', 'TXN555666'),
(8, 1000.00, 'Card', 'TXN000111'),
(9, 300.00, 'Nagad', 'TXN999222'),
(10, 5000.00, 'Card', 'TXN888333'),
(8, 150.00, 'BKash', 'TXN444333'),
(9, 750.00, 'Nagad', 'TXN222111'),
(10, 2000.00, 'Card', 'TXN777888'),
(8, 100.00, 'BKash', 'TXN111000');