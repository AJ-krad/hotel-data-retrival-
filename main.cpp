#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Room information structure
struct RoomInfo {
    int roomNumber;
    string guestName;
    string checkInDate;
    string checkOutDate;
    double roomRate;
};

// Node structure for the BST
struct Node {
    RoomInfo info;
    Node* left;
    Node* right;

    // Constructor without initializer list
    Node(RoomInfo& data) {
        info = data;  // Assign room information
        left = NULL;  // Initialize left child to NULL
        right = NULL; // Initialize right child to NULL
    }
};

// HotelManager class managing room info using BST
class HotelManager {
private:
    Node* root;

public: // Make the constructor public
    // Constructor without initializer list
    HotelManager() {
        root = NULL; // Initialize root to NULL
    }

    // Insert a room into the BST
    Node* insert(Node* node, RoomInfo& info) {
        if (node == NULL) {
            node = new Node(info); // Create new node if empty spot is found
        } else if (info.roomNumber < node->info.roomNumber) {
            node->left = insert(node->left, info); // Insert in the left subtree
        } else if (info.roomNumber > node->info.roomNumber) {
            node->right = insert(node->right, info); // Insert in the right subtree
        }
        return node;
    }

    // Search for a room in the BST by room number
    Node* search(Node* node, int roomNumber) {
        if (node == NULL || node->info.roomNumber == roomNumber) {
            return node; // Room found or end of tree
        }
        if (roomNumber < node->info.roomNumber) {
            return search(node->left, roomNumber); // Search in the left subtree
        }
        return search(node->right, roomNumber); // Search in the right subtree
    }

    // In-order traversal to print all rooms
    void inorder(Node* node) {
        if (node == NULL) return; // Base case: Empty node
        inorder(node->left); // Visit left subtree
        cout << "Room: " << node->info.roomNumber
             << ", Guest: " << node->info.guestName
             << ", Rate: Rs." << fixed << setprecision(2) << node->info.roomRate
             << endl;
        inorder(node->right); // Visit right subtree
    }

    // Insert a new room
    void insertRoom(RoomInfo& info) {
        root = insert(root, info); // Call insert on root
        cout << "Room added successfully." << endl;
    }

    // Search and print a room by room number
    void searchRoom(int roomNumber) {
        Node* result = search(root, roomNumber); // Search for the room
        if (result != NULL) {
            cout << "Room found: " << result->info.roomNumber
                 << ", Guest: " << result->info.guestName
                 << ", Rate: Rs." << fixed << setprecision(2) << result->info.roomRate
                 << endl;
        } else {
            cout << "Room not found." << endl;
        }
    }

    // Print all rooms (in-order traversal)
    void printAllRooms() {
        if (root == NULL) {
            cout << "No rooms available." << endl;
        } else {
            inorder(root); // Call in-order traversal on root
        }
    }
};

int main() {
    HotelManager manager; // Now accessible
    int choice;

    do {
        cout << "\nHotel Management Menu:\n";
        cout << "1. Add Room\n";
        cout << "2. Search Room\n";
        cout << "3. View All Rooms\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                RoomInfo info;
                cout << "Enter room number: ";
                cin >> info.roomNumber;
                cout << "Enter guest name (single word): ";
                cin >> info.guestName;
                cout << "Enter check-in date (format: YYYY-MM-DD): ";
                cin >> info.checkInDate;
                cout << "Enter check-out date (format: YYYY-MM-DD): ";
                cin >> info.checkOutDate;
                cout << "Enter room rate: ";
                cin >> info.roomRate;
                manager.insertRoom(info); // Insert room info
                break;
            }
            case 2: {
                int roomNumber;
                cout << "Enter room number to search: ";
                cin >> roomNumber;
                manager.searchRoom(roomNumber); // Search for the room
                break;
            }
            case 3: {
                manager.printAllRooms(); // Print all rooms
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
