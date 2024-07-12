#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Base class for a general Accommodation
class Accommodation {
protected:
    string address;
    double rent;
    bool isAvailable;

public:
    Accommodation(string addr, double r, bool avail) : address(addr), rent(r), isAvailable(avail) {}

    virtual void displayInfo() = 0;  // Pure virtual function for displaying accommodation info

    string getAddress() const {
        return address;
    }

    double getRent() const {
        return rent;
    }

    bool availability() const {
        return isAvailable;
    }

    void setAvailability(bool avail) {
        isAvailable = avail;
    }
};

// Derived class for a Flat
class Flat : public Accommodation {
private:
    int numberOfRooms;

public:
    Flat(string addr, double r, bool avail, int rooms)
        : Accommodation(addr, r, avail), numberOfRooms(rooms) {}

    void displayInfo() override {
        cout << "Address: " << address << endl;
        cout << "Rent: " << rent << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
        cout << "Number of rooms: " << numberOfRooms << endl;
    }

    int getNumberOfRooms() const {
        return numberOfRooms;
    }
};

// Accommodation management system
class AccommodationManager {
private:
    vector<Accommodation*> accommodations;

public:
    void addAccommodation(Accommodation* accommodation) {
        accommodations.push_back(accommodation);
    }

    void displayAllAccommodations() {
        for (auto accommodation : accommodations) {
            accommodation->displayInfo();
            cout << "--------------------------" << endl;
        }
    }

    void sortAccommodationsByRent() {
        sort(accommodations.begin(), accommodations.end(), [](Accommodation* a, Accommodation* b) {
            return a->getRent() < b->getRent();
        });
    }

    vector<Accommodation*> searchByAvailability() {
        vector<Accommodation*> availableAccommodations;
        for (auto accommodation : accommodations) {
            if (accommodation->availability()) {
                availableAccommodations.push_back(accommodation);
            }
        }
        return availableAccommodations;
    }
};

int main() {
    AccommodationManager manager;

    // Adding some flats
    manager.addAccommodation(new Flat("123 Main St", 1200.00, true, 2));
    manager.addAccommodation(new Flat("456 Elm St", 1500.00, false, 3));
    manager.addAccommodation(new Flat("789 Maple St", 1100.00, true, 1));

    cout << "All accommodations:" << endl;
    manager.displayAllAccommodations();

    cout << "Sorting accommodations by rent:" << endl;
    manager.sortAccommodationsByRent();
    manager.displayAllAccommodations();

    cout << "Available accommodations:" << endl;
    vector<Accommodation*> availableAccommodations = manager.searchByAvailability();
    for (auto accommodation : availableAccommodations) {
        accommodation->displayInfo();
        cout << "--------------------------" << endl;
    }

    return 0;
}
