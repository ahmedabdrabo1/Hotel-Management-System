#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room {
public:
    int roomId;
    string type;
    float price;
    string status;
    string features;
    Room* next;

    Room() {
        roomId = 0;
        type = "";
        price = 0;
        status = "";
        features = "";
        next = NULL;
    }
};
class RoomList {
public:
    Room* roomsHead;
    Room* roomsTail;
    RoomList() {
        roomsHead = NULL;
        roomsTail = NULL;
    }
    void attachRoom(Room* newRoom) {
        if (roomsHead == NULL) {
            roomsHead = newRoom;
            roomsTail = newRoom;
        }
        else {
            roomsTail->next = newRoom;
            roomsTail = newRoom;
        }
    }
    void readRooms() {
        ifstream file("Path\\text\\Room.txt");
        string myText;
        if (file.is_open()) {
            string data[5];
            int ct = 0, put = 0;
            while (getline(file, myText)) {
                if (ct > 0) {
                    for (int i = 0; i < myText.length(); i++) {
                        if (myText[i] == ',') {
                            put++;
                        }
                        else {
                            if (put < 5) {
                                data[put] += myText[i];
                            }
                        }
                    }
                    put = 0;
                    Room* newRoom = new Room();
                    newRoom->roomId = stoi(data[0]);
                    newRoom->type = data[1];
                    newRoom->price = stof(data[2]);
                    newRoom->status = data[3];
                    newRoom->features = data[4];
                    newRoom->next = NULL;
                    attachRoom(newRoom);
                    for (int h = 0; h < 5; h++) {
                        data[h].clear();
                    }
                }
                ct++;
            }
            file.close();
        }
        else {
            cout << "Unable to open the file" << endl;
        }
    }
    ~RoomList() {
        while (roomsHead != NULL) {
            Room* temp = roomsHead;
            roomsHead = roomsHead->next;
            delete temp; 
        }
    }
};

class Booking {
public:
    int bookingId;
    int guestId;
    int roomId;
    string checkinDate;
    string checkoutDate;
    float totalCost;
    Booking* next;

    Booking() {
        bookingId = 0;
        guestId = 0;
        roomId = 0;
        checkinDate = "";
        checkoutDate = "";
        totalCost = 0;
        next = NULL;
    }
};
class BookingList {
public:
    Booking* bookingsHead;
    Booking* bookingsTail;

    BookingList() {
        bookingsHead = NULL;
        bookingsTail = NULL;
    }
    void attachBooking(Booking* newBooking) {
        if (bookingsHead == NULL) {
            bookingsHead = newBooking;
            bookingsTail = newBooking;
        }
        else {
            bookingsTail->next = newBooking;
            bookingsTail = newBooking;
        }
    }
    void readBookings() {
        ifstream file("Path\\text\\Booking.txt");
        string myText;
        if (file.is_open()) {
            string data[6];
            int ct = 0, put = 0;
            while (getline(file, myText)) {
                if (ct > 0) {
                    for (int i = 0; i < myText.length(); i++) {
                        if (myText[i] == ',') {
                            put++;
                        }
                        else {
                            data[put] += myText[i];
                        }
                    }
                    put = 0;
                    Booking* newBooking = new Booking();
                    newBooking->bookingId = stoi(data[0]);
                    newBooking->guestId = stoi(data[1]);
                    newBooking->roomId = stoi(data[2]);
                    newBooking->checkinDate = data[3];
                    newBooking->checkoutDate = data[4];
                    newBooking->totalCost = stof(data[5]);
                    newBooking->next = NULL;
                    attachBooking(newBooking);
                    for (int h = 0; h < 6; h++) {
                        data[h].clear();
                    }
                }
                ct++;
            }
            file.close();
        }
        else {
            cout << "Unable to open the file" << endl;
        }
    }
    ~BookingList() {
        while (bookingsHead != NULL) {
            Booking* temp = bookingsHead;
            bookingsHead = bookingsHead->next;
            delete temp;
        }
    }
};



class Guest {
public:
    int id;
    string name;
    string password;
    Guest* next;

    Guest() {
        id = 0;
        name = "";
        password = "";
        next = NULL;
    }
};
class GuestList {
public:
    Guest* guestsHead;
    Guest* guestsTail;
    Guest* currentGuest;
    GuestList() {
        guestsHead = NULL;
        guestsTail = NULL;
        currentGuest = NULL;
    }
    void attachGuest(Guest* newGuest) {
        if (guestsHead == NULL) {
            guestsHead = newGuest;
            guestsTail = newGuest;
        }
        else {
            guestsTail->next = newGuest;
            guestsTail = newGuest;
        }
    }
    void readGuests() {
        ifstream file("Path\\text\\Guest.txt");
       string myText;
        if (file.is_open()) {
            string data[3];
            int ct = 0, put = 0;
            while (getline(file, myText)) {
                if (ct > 0) {
                    for (int i = 0; i < myText.length(); i++) {
                        if (myText[i] == ',') {
                            put++;
                        }
                        else {
                            if (put < 3) {
                                data[put] += myText[i];
                            }
                        }
                    }
                    put = 0;
                    Guest* newGuest = new Guest();
                    newGuest->id = stoi(data[0]);
                    newGuest->name = data[1];
                    newGuest->password = data[2];
                    newGuest->next = NULL;
                    attachGuest(newGuest);
                    for (int h = 0; h < 3; h++)
                    {
                        data[h].clear();
                    }
                }
                ct++;
            }
            file.close();
        }
        else {
            cout << "Unable to open the file" << endl;
        }
    }

    void registerGuest() {
        string name, password;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Password: ";
        cin >> password;

        Guest* newGuest = new Guest();

        if (guestsTail == NULL) {
            newGuest->id = 1;
        }
        else {
            newGuest->id = guestsTail->id + 1;
        }

        newGuest->name = name;
        newGuest->password = password;
        attachGuest(newGuest);
        ofstream file("Path\\text\\Guest.txt", ios::app);
        if (file.is_open()) {
            file << newGuest->id << "," << newGuest->name << "," << newGuest->password << endl;
        }
        else {
            cout << "Unable to open the file" << endl;
        }
        file.close();
    }
    void loginGuest() {
        int id;
        string password;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;

        Guest* temp = guestsHead;
        while (temp != NULL) {
            if (temp->id == id && temp->password == password) {
                currentGuest = temp;
                cout << "Login successful. Welcome, " << temp->name << endl;
                return;
            }
            temp = temp->next;
        }
    }

    void logoutGuest() {
        if (currentGuest != NULL) {
            cout << "Goodbye, " << currentGuest->name << endl;
            currentGuest = NULL;
        }
        else {
            cout << "No guest is currently logged in." << endl;
        }
    }


    void searchRooms(RoomList& R) {

        int choice;
        cout << "Search Rooms by:" << endl;
        cout << "1. Type" << endl;
        cout << "2. Status " << endl;
        cout << "3. Max Price" << endl;
        cout << "choice (1-3): ";
        cin >> choice;

        Room* current = R.roomsHead;
        int ct = 0;

        if (choice == 1) {
            string searchType;
            cout << "Enter room type: ";
            cin >> searchType;

            while (current != NULL) {
                if (current->type == searchType) {
                    cout << "Room ID: " << current->roomId << ", Type: " << current->type << ", Price: " << current->price << ", Status: " << current->status << ", Features: " << current->features << endl;
                    ct = 1;
                }
                current = current->next;
            }
        }
        else if (choice == 2) {
            string searchStatus;
            cout << "Enter room status: ";
            cin >> searchStatus;

            while (current != NULL) {
                if (current->status == searchStatus) {
                    cout << "Room ID: " << current->roomId << ", Type: " << current->type << ", Price: " << current->price << ", Status: " << current->status << ", Features: " << current->features << endl;
                    ct = 1;
                }
                current = current->next;
            }
        }
        else if (choice == 3) {
            float maxPrice;
            cout << "Enter maximum price: ";
            cin >> maxPrice;
            float minPrice;
            cout << "Enter minimum price: ";
            cin >> minPrice;

            while (current != NULL) {
                if (minPrice <= current->price && current->price <= maxPrice) {
                    cout << "Room ID: " << current->roomId << ", Type: " << current->type << ", Price: " << current->price << ", Status: " << current->status << ", Features: " << current->features << endl;
                    ct = 1;
                }
                current = current->next;
            }
        }
        else {
            return;
        }
    }

    void BookRoom(int guestId,int roomId, string inDate, string outDate, BookingList& B, RoomList& R) {
        Room* room = R.roomsHead;
        while (room != NULL) {
            if (room->roomId == roomId && room->status == "available") {
                string dayOne = "";
                string monthOne = "";
                string yearOne = "";
                string dayTwo = "";
                string monthTwo = "";
                string yearTwo = "";

                int ct = 0;
                for (int i = 0; i < inDate.length(); i++) {
                    if (inDate[i] != '/' && ct == 0) {
                        dayOne += inDate[i];
                        ct = 1;
                    }
                    else {
                        break;
                    }
                }
                ct = 0;
                for (int i = 0; i < outDate.length(); i++) {
                    if (outDate[i] != '/' && ct == 0) {
                        dayTwo += outDate[i];
                        ct = 1;
                    }
                    else {
                        break;
                    }
                }
                ct = 0;
                for (int i = 0; i < inDate.length(); i++) {
                    if (inDate[i] == '/' && ct == 0) {
                        ct = 1;
                    }
                    else if (ct == 1) {
                        if (inDate[i] == '/') {
                            break;
                        }
                        monthOne += inDate[i];
                    }
                }
                ct = 0;
                for (int i = 0; i < outDate.length(); i++) {
                    if (outDate[i] == '/' && ct == 0) {
                        ct = 1;
                    }
                    else if (ct == 1) {
                        if (outDate[i] == '/') {
                            break;
                        }
                        monthTwo += outDate[i];
                    }
                }
                ct = 0;

                for (int i = 0; i < inDate.length(); i++) {
                    if (inDate[i] == '/' && (ct == 0 || ct==1 ) ) {
                        ct++;
                    }
                    else if (ct == 2) {
                        yearOne += inDate[i];
                    }
                }
                ct = 0;
                for (int i = 0; i < outDate.length(); i++) {
                    if (outDate[i] == '/' && (ct == 0 || ct == 1)) {
                        ct++;
                    }
                    else if (ct == 2) {
                        yearTwo += outDate[i];
                    }
                }

                int days = (stoi(dayTwo) + stoi(monthTwo) * 30 + stoi(yearTwo) * 365) - (stoi(dayOne) + stoi(monthOne) * 30 + stoi(yearOne) * 365);

                float price = (days * room->price) * (1 + 0.14);

                Booking* newBooking = B.bookingsHead;
                if (B.bookingsTail == NULL) {
                    newBooking->bookingId = 1;
                }
                else {
                    newBooking->bookingId = B.bookingsTail->bookingId + 1;
                }
                newBooking->guestId = guestId;
                newBooking->roomId = roomId;
                newBooking->checkinDate = inDate;
                newBooking->checkoutDate = outDate;
                newBooking->totalCost = price;
                B.attachBooking(newBooking);

                ofstream file("Path\\text\\Booking.txt", ios::app);
                if (file.is_open()) {
                    Booking* temp = B.bookingsHead;
                        file << temp->bookingId << "," << temp->guestId << "," << temp->roomId << "," << temp->checkinDate << "," << temp->checkoutDate << "," << temp->totalCost << endl;
                        temp = temp->next;
                    file.close();
                }
                else {
                    cout << "Unable to open the file" << endl;
                }

                checkIn(roomId, R);
                return;
            }
            room = room->next;
        }
    }

    void CancelBooking(int guestId, int bookingId, BookingList& B, RoomList& R) {

        Booking* current = B.bookingsHead;
        Booking* prev = NULL;
        while (current != NULL) {
            if (current->guestId == guestId && current->bookingId == bookingId) {
                int total = 0;
                string currentDay;
                cout << "Enter currentDay date (DD/MM/YYYY): ";
                cin >> currentDay;

                string currentInDay = "";
                int ct = 0;
                for (int i = 0; i < currentDay.length(); i++) {
                    if (currentDay[i] != '/' && ct != 1) {
                        currentInDay += currentDay[i];
                    }
                    else if (ct == 0) {
                        ct = 1;
                    }
                }
                string InDate = "";
                ct = 0;
                for (int i = 0; i < current->checkinDate.length(); i++) {
                    if (current->checkinDate[i] != '/' && ct != 1) {
                        InDate += current->checkinDate[i];
                    }
                    else if (ct == 0) {
                        ct = 1;
                    }
                }
                total = stoi(InDate) - stoi(currentInDay);
                if (total >= 1) {
                    checkOut(current->roomId, R);
                    if (prev == NULL) {
                        B.bookingsHead = current->next;
                    }
                    else {
                        prev->next = current->next;
                    }
                    delete current;
                    
                    ofstream file("Path\\text\\Booking.txt");
                    file << "BookingId" << ',' << "GuestId" << ',' << "RoomId" << ',' << "CheckInDate" << ',' << "CheckOutDate" << ',' << "TotalCost" << endl;
                    if (file.is_open()) {
                        Booking* tempOne = B.bookingsHead;
                        while (tempOne != NULL) {
                            file << tempOne->bookingId << ","
                                << tempOne->guestId << ","
                                << tempOne->roomId << ","
                                << tempOne->checkinDate << ","
                                << tempOne->checkoutDate << ","
                                << tempOne->totalCost << endl;
                            tempOne = tempOne->next;
                        }
                        file.close();
                    }
                    else {
                        cout << "Unable to open the file" << endl;
                    }

                    return;
                }
                else {
                    cout << "Booking cannot be cancelled";
                    return;
                }
            }
            prev = current;
            current = current->next;
        }
    }

    void ViewBookingHistory(int guestId, BookingList& B) {
        Booking* current = B.bookingsHead;
        cout << "BookingId" << ',' << "GuestId" << ',' << "RoomId" << ',' << "CheckInDate" << ',' << "CheckOutDate" << ',' << "TotalCost" << endl;
        while (current != nullptr) {
            if (current->guestId == guestId) {
                cout << current->bookingId << "," << current->guestId << "," << current->roomId << "," << current->checkinDate << "," << current->checkoutDate << "," << current->totalCost << endl;
            }
            current = current->next;
        }
    }

    void checkIn(int roomId,RoomList& R) {
        Room* room = R.roomsHead;
        while (room != NULL) {
            if (room->roomId == roomId) {
                if (room->status == "available") {
                    room->status = "booked";
                    cout << "Checkin successful." << endl;
                }
                else {
                    cout << "Room is already booked." << endl;
                    return;
                }
            }
            room = room->next;
        }
        ofstream file("Path\\text\\Room.txt");
        file << "roomId" << ',' << "type" << ',' << "price" << ',' << "status" << ',' << "features" << endl;

        if (file.is_open()) {
            Room* temp = R.roomsHead;
            while (temp != NULL) {
                file << temp->roomId << "," << temp->type << "," << temp->price << "," << temp->status << "," << temp->features << endl;
                temp = temp->next;
            }
            file.close();
        }
        else {
            cout << "Unable to open the file" << endl;
        }
    }

    void checkOut(int roomId, RoomList& R) {
        Room* room = R.roomsHead;
        while (room != NULL) {
            if (room->roomId == roomId) {
                if (room->status == "booked") {
                    room->status = "available";
                    cout << "Checkout successful" << endl;
                }
                else {
                    cout << "Room was not marked as booked." << endl;
                    return;
                }
            }
            room = room->next;
        }
        ofstream file("Path\\text\\Room.txt");
        file << "roomId" << ',' << "type" << ',' << "price" << ',' << "status" << ',' << "features" << endl;

        if (file.is_open()) {
            Room* temp = R.roomsHead;
            while (temp != NULL) {
                file << temp->roomId << "," << temp->type << "," << temp->price << "," << temp->status << "," << temp->features << endl;
                temp = temp->next;
            }
            file.close();
        }
        else {
            cout << "Unable to open the file" << endl;
        }
    }

    ~GuestList() {
        while (guestsHead != NULL) {
            Guest* temp = guestsHead;
            guestsHead = guestsHead->next;
            delete temp;
        }
    }
};
class Admin {
public:
    int id;
    string name;
    string password;
    Admin* next;

    Admin() {
        id = 0;
        name = "";
        password = "";
        next = NULL;
    }
};
class AdminList {
public:
    Admin* adminsHead;
    Admin* adminsTail;
    Admin* currentAdmin;

    AdminList() {
        adminsHead = NULL;
        adminsTail = NULL;
        currentAdmin = NULL;
    }
    void attachAdmin(Admin* newAdmin) {
        if (adminsHead == NULL) {
            adminsHead = newAdmin;
            adminsTail = newAdmin;
        }
        else {
            adminsTail->next = newAdmin;
            adminsTail = newAdmin;
        }
    }
    void readAdmins() {
        ifstream file("Path\\text\\Admin.txt");
        string myText;
        if (file.is_open()) {
            string data[3];
            int ct = 0, put = 0;
            while (getline(file, myText)) {
                if (ct > 0) {
                    for (int i = 0; i < myText.length(); i++) {
                        if (myText[i] == ',') {
                            put++;
                        }
                        else {
                            if (put < 3) {
                                data[put] += myText[i];
                            }
                        }
                    }
                    put = 0;
                    Admin* newAdmin = new Admin();
                    newAdmin->id = stoi(data[0]);
                    newAdmin->name = data[1];
                    newAdmin->password = data[2];
                    newAdmin->next = NULL;
                    attachAdmin(newAdmin);
                    for (int h = 0; h < 3; h++)
                    {
                        data[h].clear();
                    }
                }
                ct++;
            }
            file.close();
        }
        else {
            cout << "Unable to open the file" << endl;
        }
    }
    void loginAdmin() {
        int id;
        string password;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;

        Admin* temp = adminsHead;
        while (temp != NULL) {
            if (temp->id == id && temp->password == password) {
                currentAdmin = temp;
                cout << "Login successful "<< endl;
                return;
            }
            temp = temp->next;
        }
    }
    void logoutAdmin() {
        if (currentAdmin != NULL) {
            cout << "Goodbye, " << currentAdmin->name << endl;
            currentAdmin = NULL;
        }
        else {
            cout << "No admin is currently logged in." << endl;
        }
    }
    void AddRooms(RoomList& R) {
        string type;
        float price;
        string status;
        string features;

        cout << "Enter type: ";
        cin >> type;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter status: ";
        cin >> status;
        cout << "Enter features: ";
        cin >> features;

        Room* newRoom = new Room();
        if (R.roomsTail == NULL) {
            newRoom->roomId = 1;
        }
        else {
            newRoom->roomId = R.roomsTail->roomId + 1;
        }
        newRoom->type = type;
        newRoom->price = price;
        newRoom->status = status;
        newRoom->features = features;
        newRoom->next = NULL;

        R.attachRoom(newRoom);

        ofstream file("Path\\text\\Room.txt", ios::app);
        if (file.is_open()) {
            file << newRoom->roomId << "," << newRoom->type << "," << newRoom->price << "," << newRoom->status << "," << newRoom->features << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
        file.close();
        cout << "Room added successfully." << endl;
    }
    void EditRoom(int roomId, RoomList& R) {

        Room* current = R.roomsHead;
        while (current != NULL) {
            if (current->roomId == roomId) {
                cout << "Current Type: " << current->type << endl;
                cout << "Enter new Type: ";
                cin >> current->type;

                cout << "Current Price: " << current->price << endl;
                cout << "Enter new Price: ";
                cin >> current->price;

                cout << "Current Status: " << current->status << endl;
                cout << "Enter new Status: ";
                cin >> current->status;

                cout << "Current Features: " << current->features << endl;
                cout << "Enter new Features: ";
                cin >> current->features;
                ofstream file("Path\\text\\Room.txt");
                file << "roomId" << ',' << "type" << ',' << "price" << ',' << "status" << ',' << "features" << endl;
                Room* temp = R.roomsHead;
                while (temp) {
                    file << temp->roomId << "," << temp->type << "," << temp->price << "," << temp->status << "," << temp->features << endl;
                    temp = temp->next;
                }
                cout << "Room updated" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Room not found" << endl;
    }
    void DeleteRoom(int roomId, RoomList& R) {

        Room* current = R.roomsHead;
        Room* prev = NULL;
        while (current != NULL) {
            if (current->roomId == roomId) {
                if (prev == NULL) {
                    R.roomsHead = current->next;
                }
                else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Room with ID " << roomId << " deleted from list." << endl;

                ofstream file("C:\\Users\\Afkar\\Desktop\\ProjectC++\\text\\Room.txt");
                file << "roomId" << ',' << "type" << ',' << "price" << ',' << "status" << ',' << "features" << endl;
                if (file.is_open()) {
                    Room* temp = R.roomsHead;
                    while (temp != NULL) {
                        file << temp->roomId << "," << temp->type << "," << temp->price << "," << temp->status << "," << temp->features << endl;
                        temp = temp->next;
                    }
                    file.close();
                }
                else {
                    cout << "Unable to open the file" << endl;
                }
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << " not found in the list." << endl;
    }
    void ViewAllBookings(BookingList& B) {
        Booking * current = B.bookingsHead;
        cout << "BookingId" << ',' << "GuestId" << ',' << "RoomId" << ',' << "CheckInDate" << ',' << "CheckOutDate" << ',' << "TotalCost" << endl;
        while (current != NULL) {

            cout << current->bookingId << ","
                << current->guestId << ","
                << current->roomId << ","
                << current->checkinDate << ","
                << current->checkoutDate << ","
                << current->totalCost << endl;
            current = current->next;
        }
    }
    void MonitorOccupancyRate(RoomList& R) {
        Room* current = R.roomsHead;
        float Totalrooms = 0;
        int currentlybooked = 0;
        while (current != NULL) {
            Totalrooms++;
            if (current->status == "booked") {
                currentlybooked++;
            }
            current = current->next;
        }
        cout << "Totalrooms: " << Totalrooms << endl;
        cout << "currentlybooked: " << currentlybooked << endl;
        float OccupancyRate = 100 * (currentlybooked / Totalrooms);
        cout << "OccupancyRate: " << OccupancyRate << endl;
    }

    void dailyIncome(string date, BookingList& B) {
        Booking* current = B.bookingsHead;
        float total = 0;

        while (current != NULL) {
            if (current->checkinDate == date) {
                total += current->totalCost;
            }
            current = current->next;
        }

        cout << "Total income is: " << total << endl;
    }

    void monthlyIncome(string Month, BookingList& B) {
        Booking* current = B.bookingsHead;
        float total = 0;
        while (current != NULL) {
            string date = "";
            int ct = 0;
            for (int i = 0; i < current->checkinDate.length(); i++) {
                if (current->checkinDate[i] == '/' && ct == 0) {
                    ct = 1;
                }
                else if (ct == 1) {
                    date += current->checkinDate[i];
                }
            }
            if (date == Month) {
                total += current->totalCost;
            }
            current = current->next;
        }

        cout << "Total income for " << Month << " is: " << total << endl;
    }
    ~AdminList() {
        while (adminsHead != NULL) {
            Admin* temp = adminsHead;
            adminsHead = adminsHead->next;
            delete temp;
        }
    }
};
int main() {
    GuestList G;
    AdminList A;
    BookingList B;
    RoomList R;

    R.readRooms();
    G.readGuests();
    A.readAdmins();
    B.readBookings();

    int Choice = 0;
    int Run = 1;

    while (Run == 1) {
        cout << endl << endl << "===== Hotel Management System =====" << endl;
        cout << "1. Guest" << endl << "2. Admin" << endl << "3. Exit" << endl;
        cout << "Select role: ";
        cin >> Choice;

        if (Choice == 1) { 
            int guestChoice = 0;
            int guestRunning = 1;

            while (guestRunning == 1) {
                cout << endl << endl << "===== Guest Menu =====" << endl;
                cout << "1. Register" << endl << "2. Login" << endl << "3. Back" << endl;
                cout << "Choose action: ";
                cin >> guestChoice;

                if (guestChoice == 1) {
                    G.registerGuest();
                }
                else if (guestChoice == 2) {
                    G.loginGuest();
                    if (G.currentGuest != NULL ) {
                        int loggedInChoice = 0;
                        int loggedInRunning = 1;

                        while (loggedInRunning == 1) {
                            cout << endl << endl << "===== Welcome " << G.currentGuest->name << " =====" << endl;
                            cout << "1. Search Rooms" << endl << "2. Book Room" << endl << "3. Cancel Booking" << endl;
                            cout << "4. View Booking History" << endl << "5. Check-In" << endl << "6. Check-Out" << endl << "7. Logout" << endl;
                            cout << "Choose service: ";
                            cin >> loggedInChoice;

                            if (loggedInChoice == 1) {
                                G.searchRooms(R);
                            }
                            else if (loggedInChoice == 2) {
                                int roomId;
                                string checkin, checkout;
                                cout << "Enter room ID: ";
                                cin >> roomId;
                                cout << "Check-in date (DD/MM/YYYY): ";
                                cin >> checkin;
                                cout << "Check-out date (DD/MM/YYYY): ";
                                cin >> checkout;
                                G.BookRoom(G.currentGuest->id, roomId, checkin, checkout, B, R);
                            }
                            else if (loggedInChoice == 3) {
                                int bookingId;
                                cout << "Enter booking ID to cancel: ";
                                cin >> bookingId;
                                G.CancelBooking(G.currentGuest->id, bookingId, B, R);
                            }
                            else if (loggedInChoice == 4) {
                                G.ViewBookingHistory(G.currentGuest->id, B);
                            }
                            else if (loggedInChoice == 5) {
                                int roomId;
                                cout << "Enter room ID to check-in: ";
                                cin >> roomId;
                                G.checkIn(roomId, R);
                            }
                            else if (loggedInChoice == 6) {
                                int roomId;
                                cout << "Enter room ID to check-out: ";
                                cin >> roomId;
                                G.checkOut(roomId, R);
                            }
                            else if (loggedInChoice == 7) {
                                G.logoutGuest();
                                loggedInRunning = 0;
                            }
                            else {
                                cout << "Invalid choice!" << endl;
                            }
                        }
                    }
                }
                else if (guestChoice == 3) {
                    guestRunning = 0;
                }
                else {
                    cout << "Invalid choice!" << endl;
                }
            }
        }
        else if (Choice == 2) { 
            A.loginAdmin();
            if (A.currentAdmin != NULL) {
                int adminChoice = 0;
                int adminRunning = 1;

                while (adminRunning == 1) {
                    cout << endl << endl << "===== Admin Panel =====" << endl;
                    cout << "1. Add Room" << endl << "2. Edit Room" << endl << "3. Delete Room" << endl;
                    cout << "4. View All Bookings" << endl << "5. Occupancy Rate" << endl << "6. Daily Income" << endl;
                    cout << "7. Monthly Income" << endl << "8. Logout" << endl;
                    cout << "Choose service: ";
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        A.AddRooms(R);
                    }
                    else if (adminChoice == 2) {
                        int roomId;
                        cout << "Enter room ID to edit: ";
                        cin >> roomId;
                        A.EditRoom(roomId, R);
                    }
                    else if (adminChoice == 3) {
                        int roomId;
                        cout << "Enter room ID to delete: ";
                        cin >> roomId;
                        A.DeleteRoom(roomId, R);
                    }
                    else if (adminChoice == 4) {
                        A.ViewAllBookings(B);
                    }
                    else if (adminChoice == 5) {
                        A.MonitorOccupancyRate(R);
                    }
                    else if (adminChoice == 6) {
                        string date;
                        cout << "Enter date (DD/MM/YYYY): ";
                        cin >> date;
                        A.dailyIncome(date, B);
                    }
                    else if (adminChoice == 7) {
                        string month;
                        cout << "Enter month (MM/YYYY): ";
                        cin >> month;
                        A.monthlyIncome(month, B);
                    }
                    else if (adminChoice == 8) {
                        A.logoutAdmin();
                        adminRunning = 0;
                    }
                    else {
                        cout << "Invalid choice!" << endl;
                    }
                }
            }
        }
        else if (Choice == 3) {
            Run = 0;
            cout << endl << "Thank you " << endl;
        }
    }
    return 0;
}