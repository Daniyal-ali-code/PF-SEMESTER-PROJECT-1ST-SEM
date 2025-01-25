# 💸 **Expense Tracking System**

The **Expense Tracking System** is a console-based application built to simplify personal expense management. With features like secure registration, user-specific expense tracking, and an intuitive interface, this application is your go-to tool for managing day-to-day spending. 

---

## 🏷️ **Key Features**

### 🔐 1. User Registration & Login
- **Secure User Registration**: 
  - Users can create accounts by entering a unique username and password.
  - Ensures no duplicate usernames are allowed for privacy and security.
- **Login Functionality**: 
  - Users log in by entering their credentials.
  - Displays appropriate error messages for invalid credentials or nonexistent accounts.

---

### 💵 2. Expense Management

#### ➕ **Add Expense**
- Easily log daily expenses by specifying a description and amount.
- **Example**:
  - Description: *Lunch at Cafe*
  - Amount: *500 PKR*
- All expenses are stored in a user-specific file for privacy and security.

#### 📋 **View Expenses**
- Provides a **clean, tabular display** of all recorded expenses using formatted output for readability.
- **Example Table**:
  ```
  DESCRIPTION                     AMOUNT (PKR)
  --------------------------------------------
  Lunch at Cafe                    500.00
  Grocery Shopping                1500.00
  Uber Ride                        300.00
  ```

#### ❌ **Delete Expense**
- Remove specific expense entries by entering their description.
- **Example**:
  - Enter "Uber Ride" to delete all entries with this description.
- Displays confirmation upon successful deletion and updates the expense file.

#### 🧮 **Total Expenses**
- Calculates and displays the total amount spent across all recorded expenses.
- **Example Output**:
  ```
  Total Expenses: PKR 2300.00
  ```

---

### 📞 3. Contact Helpline
- Provides contact details for support:
  - **Daniyal Ali**: 📞 +92 333 0276929
  - **Ayesha Zafar**: 📞 +92 344 3822791
  - **Syed Abdul Muiz**: 📞 +92 341 2287624

---

### ⚙️ 4. User-Friendly Error Handling
- **Invalid Input Handling**: Displays helpful messages for non-numeric inputs or invalid menu choices.
- **File Handling Errors**: Gracefully manages file-related issues like missing user files or expense records.

---

### 🔒 5. Secure & Organized File Management
- Each user has dedicated files for secure and organized data storage:
  - **`username.txt`**: Stores the user's credentials.
  - **`username_expenses.txt`**: Stores all expense entries.
- Example for a user named *John*:
  - `John.txt` → *Stores John’s username and password.*
  - `John_expenses.txt` → *Stores all of John’s expenses.*

---
### 🌟 **Thank You!**
We hope the **Expense Tracking System** makes managing your expenses simpler, smarter, and more efficient! 😊
``` 

This design emphasizes readability, provides detailed explanations of features, and uses professional formatting. Let me know if you’d like further refinements!
