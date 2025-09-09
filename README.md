# Rating System with Linked List

This project is a **C program** that simulates a simple rating system.  
Users can rate items, update their ratings, remove them, and query averages.  
The ratings are stored in memory using a **dynamic linked list** data structure.

---

## 📖 Project Overview
- Each **Node** in the linked list stores:
  - userID
  - itemID
  - rating (float, 1–5)

- The program supports:
  - Adding new ratings
  - Updating existing ratings
  - Removing ratings
  - Querying a specific rating
  - Calculating average ratings for items

---

## ⚙️ Features

### 🔹 Commands
- INSERT userID itemID value  
  Adds a new rating or updates an existing one.  
  Example:  
    INSERT 1 2 5  
    Customer rating (1, 2) is added successful

- REMOVE userID itemID  
  Removes a rating if it exists.  
  Example:  
    REMOVE 1 2  
    Customer rating (1, 2) is removed successful

- RATING userID itemID  
  Shows the rating given by a user to an item (0.0 if none).  
  Example:  
    RATING 2 1  
    Customer rating (2, 1) is: 3.5

- AVERAGE itemID  
  Calculates the average rating of an item (0.0 if none).  
  Example:  
    AVERAGE 2  
    Average rating (2) is: 4.5

---

## 🖥️ How to Run
1. Compile the program:  
   gcc hw1.c -o rating

2. Run the executable:  
   ./rating

3. Enter commands line by line. Example:  
   INSERT 1 1 5  
   INSERT 2 1 3  
   RATING 1 1  
   AVERAGE 1  
   REMOVE 1 1

---

## 📂 File Structure
Rating-System-LinkedList/  
│── hw1.c        # Main source code (Linked List implementation)  
│── Report.pdf   # Report explaining the code and screenshots  
│── README.md    # Project documentation  

---

## 📸 Example Output
INSERT 1 1 5  
Customer rating (1, 1) is added successful  

RATING 2 1  
Customer rating (2, 1) is: 3.5  

AVERAGE 2  
Average rating (2) is: 4.5  

REMOVE 2 2  
Customer rating (2, 2) does not exist  

---

## 🛠️ Technologies Used
- C language – core implementation  
- Linked List – dynamic data structure  
- Pointers – memory management  

---

## 🎓 Note
This project demonstrates how to implement a **rating system** using dynamic linked lists in C.  
It highlights data structure usage, pointer manipulation, and command-based program design.
