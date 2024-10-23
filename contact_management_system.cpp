#include <iostream>
#include <map>
#include <string>
using namespace std;
// a struct to represent a contact
struct Contact {
    string name;
    string phoneNumber;
    string email;
};

// a class to manage contacts
class ContactManager {
private:
    map<string, Contact> contacts;

public:
    // Add a new contact
    void addContact() {
        Contact newContact;
        cout << "Enter name: ";
        cin >> newContact.name;
        cout << "Enter phone number: ";
        cin >> newContact.phoneNumber;
        cout << "Enter email: ";
        cin >> newContact.email;

        contacts[newContact.name] = newContact;
        cout << "Contact added successfully!" << endl;
    }

    // View all contacts
    void viewContacts() {
        if (contacts.empty()) {
            cout << "No contacts found!" << endl;
            return;
        }

        for (const auto& contact : contacts) {
            cout << "Name: " << contact.second.name << endl;
            cout << "Phone Number: " << contact.second.phoneNumber << endl;
            cout << "Email: " << contact.second.email << endl;
            cout << endl;
        }
    }

    // Edit an existing contact
    void editContact() {
        string name;
        cout << "Enter name of contact to edit: ";
        cin >> name;

        if (contacts.find(name) == contacts.end()) {
            cout << "Contact not found!" << endl;
            return;
        }

        Contact& contact = contacts[name];
        cout << "Enter new name (press enter to skip): ";
        string newName;
        cin.ignore();
        getline(cin, newName);
        if (!newName.empty()) {
            contact.name = newName;
        }

        cout << "Enter new phone number (press enter to skip): ";
        string newPhoneNumber;
        getline(cin, newPhoneNumber);
        if (!newPhoneNumber.empty()) {
            contact.phoneNumber = newPhoneNumber;
        }

        cout << "Enter new email (press enter to skip): ";
        string newEmail;
        getline(cin, newEmail);
        if (!newEmail.empty()) {
            contact.email = newEmail;
        }

        cout << "Contact updated successfully!" << endl;
    }

    // Delete a contact
    void deleteContact() {
        string name;
        cout << "Enter name of contact to delete: ";
        cin >> name;

        if (contacts.find(name) == contacts.end()) {
            cout << "Contact not found!" << endl;
            return;
        }

        contacts.erase(name);
        cout << "Contact deleted successfully!" << endl;
    }
};

int main() {
    ContactManager manager;
    cout<<"'Welcome to Contact Management System'"<<endl;
    while (true) {
        cout << "Contact Management Program" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout<<"Enter Your Choice -> "<<endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addContact();
                break;
            case 2:
                manager.viewContacts();
                break;
            case 3:
                manager.editContact();
                break;
            case 4:
                manager.deleteContact();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}