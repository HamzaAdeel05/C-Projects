#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int total_flights = 100; // Maximum number of flights
int line_length = 256; // Maximum length of each line
const char* client_file_password = "clients_passwords.txt"; // File to store passwords
const char* booking_file = "Bookings.txt";
const char* client_file = "clients.txt"; // File to store usernames
const int MAX_BOOKINGS = 100; // Maximum number of bookings

// Function to create and write flight information to a file
void createFlightInformationFile() {
    ofstream myfile("Flight Information.txt");
    if (myfile.is_open()) {
        myfile << "\t\t\tDomestic Flight Routes\n"
               << "---------------------------------------------------------------------------------------------\n\n"
               << "1. Karachi (KHI) to Lahore (LHE)\n"
               << "   - Airlines: FlyJinnah, PIA, Airblue, Airsial\n"
               << "   - Flight Duration: Approximately 1 hour and 40 minutes\n"
               << "   - Frequency: Daily flights available, with multiple departures throughout the day.\n"
               << "   - Ticket Prices: Start from PKR 1,399, with an average price around PKR 14,947.\n"
               << "   - Baggage Allowance: Carry-on baggage of 10 kg; check-in baggage varies by ticket type (23 kg for Value tickets, 46 kg for Extra tickets).\n\n"
               
               << "2. Karachi (KHI) to Islamabad (ISB)\n"
               << "   - Airlines: PIA, Airblue, FlyJinnah\n"
               << "   - Flight Duration: Approximately 2 hours\n"
               << "   - Frequency: Multiple flights daily.\n"
               << "   - Ticket Prices: Generally range from PKR 3,000 to PKR 15,000 depending on the airline and booking time.\n"
               << "   - Baggage Allowance: Similar to the Karachi to Lahore route.\n\n"
               
               << "3. Lahore (LHE) to Islamabad (ISB)\n"
               << "   - Airlines: PIA, Airblue, Serene Air\n"
               << "   - Flight Duration: Approximately 1 hour\n"
               << "   - Frequency: Frequent daily flights.\n"
               << "   - Ticket Prices: Typically range from PKR 2,500 to PKR 10,000.\n"
               << "   - Baggage Allowance: Standard allowances apply.\n\n"
               
               << "4. Karachi (KHI) to Peshawar (PEW)\n"
               << "   - Airlines: PIA, Airblue\n"
               << "   - Flight Duration: Approximately 2 hours\n"
               << "   - Frequency: Limited flights available.\n"
               << "   - Ticket Prices: Generally range from PKR 4,000 to PKR 12,000.\n"
               << "   - Baggage Allowance: Standard allowances apply.\n\n"
               
               << "5. Lahore (LHE) to Quetta (UET)\n"
               << "   - Airlines: PIA, Airblue\n"
               << "   - Flight Duration: Approximately 1 hour and 30 minutes\n"
               << "   - Frequency: Limited flights available.\n"
               << "   - Ticket Prices: Typically range from PKR 5,000 to PKR 15,000.\n"
               << "   - Baggage Allowance: Standard allowances apply.\n\n"
               
               << "6. Islamabad (ISB) to Multan (MUX)\n"
               << "   - Airlines: PIA, Airblue\n"
               << "   - Flight Duration: Approximately 1 hour\n"
               << "   - Frequency: Limited flights available.\n"
               << "   - Ticket Prices: Generally range from PKR 3,000 to PKR 10,000.\n"
               << "   - Baggage Allowance: Standard allowances apply.\n\n"
               
               << "\t\tInternational Flight Routes\n"
               << "---------------------------------------------------------------------------------------------\n\n"
               
               << "1. Karachi (KHI) to Dubai (DXB)\n"
               << "   - Airlines: Emirates, PIA, Flydubai\n"
               << "   - Flight Duration: Approximately 3 hours\n"
               << "   - Frequency: Multiple flights daily.\n"
               << "   - Ticket Prices: Typically range from PKR 20,000 to PKR 50,000.\n"
               << "   - Baggage Allowance: 7 kg carry-on; check-in baggage varies by airline.\n\n"
               
               << "2. Lahore (LHE) to Abu Dhabi (AUH)\n"
               << "   - Airlines: Etihad Airways, PIA\n"
               << "   - Flight Duration: Approximately 3 hours and 30 minutes\n"
               << "   - Frequency: Daily flights available.\n"
               << "   - Ticket Prices: Generally range from PKR 25,000 to PKR 55,000.\n"
               << "   - Baggage Allowance: Typically includes 30 kg for economy class.\n\n"
               
               << "3. Islamabad (ISB) to London (LHR)\n" 
               << "   - Airlines: PIA, British Airways\n"
               << "   - Flight Duration: Approximately 8 hours\n"
               << "   - Frequency: Several flights weekly.\n"
               << "   - Ticket Prices: Typically range from PKR 70,000 to PKR 120,000.\n"
               << "   - Baggage Allowance: Generally includes 30 kg for economy class.\n\n"
               
               << "4. Karachi (KHI) to Jeddah (JED)\n"
               << "   - Airlines: Saudi Airlines, PIA\n"
               << "   - Flight Duration: Approximately 3 hours and 30 minutes\n"
               << "   - Frequency: Multiple flights available, especially during Hajj season.\n"
               << "   - Ticket Prices: Typically range from PKR 25,000 to PKR 50,000.\n"
               << "   - Baggage Allowance: Generally includes 30 kg for economy class.\n\n"
               
               << "5. Lahore (LHE) to Toronto (YYZ)\n"
               << "   - Airlines: PIA, Air Canada\n"
               << "   - Flight Duration: Approximately 14 hours (with layovers)\n"
               << "   - Frequency: Limited flights available.\n"
               << "   - Ticket Prices: Typically range from PKR 100,000 to PKR 150,000.\n"
               << "   - Baggage Allowance: Generally includes 2 pieces of 23 kg each for economy class.\n\n"
               
               << "6. Islamabad (ISB) to Doha (DOH)\n"
               << "   - Airlines: Qatar Airways, PIA\n"
               << "   - Flight Duration: Approximately 3 hours\n"
               << "   - Frequency: Multiple flights daily.\n"
               << "   - Ticket Prices: Typically range from PKR 20,000 to PKR 40,000.\n"
               << "   - Baggage Allowance: Generally includes 30 kg for economy class.\n\n";
        myfile.close();
    } else {
        cout << "Error creating file." << endl;
    }
}

// Function to handle user login
bool login(char expected_username[], char expected_password[]) {
    char username[50], password[50];
    while (true) {
        cout << "Enter User Name: ";
        cin.getline(username, 50);
        cout << "Enter Password: ";
        cin.getline(password, 50);
        cout << endl;
        if (strcmp(username, expected_username) == 0 && strcmp(password, expected_password) == 0) {
            return true; // Successful login

        } else {
            cout << "Invalid Username or Password.\nTry again." << endl << endl;
        }
    }
}



// Function to display flight details
void flightDetails() 
{
    ifstream myread("Flight Information.txt");
    if (myread.is_open()) 
	{
        string line;
        cout << "\nFlight Details:\n";
        cout << "---------------------------------------------------------------------------------------------\n";
        while (getline(myread, line)) 
		{
            cout << line << endl; // Display each line of the flight information
        }
        myread.close();
    } 
	else 
	{
        cout << "Error opening flight information file." << endl;
    }
}
// Function to display the admin menu and handle choices
bool admin_menu() {
    int choice;
    cout << "\t   Administrator" << "\n----------------------------------------\n\n";
    while (true) {
        cout << "Menu:\n" 
             << "1. View Flight Information\n"
             << "2. Edit Flight Information\n"
             << "3. Exit\n\n"; // Added exit option
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        if (choice == 1) {
            // Read and display flight information
            ifstream myread("Flight Information.txt");
            if (myread.is_open()) {
                string line;
                while (getline(myread, line)) {
                    cout << line << endl; // Display each line of the file
                }
                myread.close();
            } else {
                cout << "Error opening file." << endl;
            }
        } else if ( choice == 2) {
            // Edit Flight Information functionality
            char lines[total_flights][line_length]; // Array to store flight information
            int lineCount = 0;
            ifstream myread("Flight Information.txt");

            // Read all lines from the file
            if (myread.is_open()) {
                while (myread.getline(lines[lineCount], line_length) && lineCount < total_flights) {
                    lineCount++;
                }
                myread.close();
            } else {
                cout << "Error opening file." << endl;
                continue;
            }

            // Display current flight information
            cout << "Current Flight Information:\n";
            for (int i = 0; i < lineCount; ++i) {
                cout << i + 1 << ". " << lines[i] << endl;
            }

            // Ask user which flight to edit
            int editChoice;
            cout << "Enter the number of the flight you want to edit (1-" << lineCount << "): ";
            cin >> editChoice;
            cin.ignore(); // Clear the newline character from the input buffer

            if (editChoice < 1 || editChoice > lineCount) {
                cout << "Invalid choice! Please select a valid flight number." << endl;
                continue;
            }

            // Get new flight information from the user
            cout << "Enter new flight information (complete line): ";
            cin.getline(lines[editChoice - 1], line_length); // Update the selected flight information

            // Write updated flight information back to the file
            ofstream mywrite("Flight Information.txt");
            if (mywrite.is_open()) {
                for (int i = 0; i < lineCount; ++i) {
                    mywrite << lines[i] << endl; // Write each line back to the file
                }
                mywrite.close();
                cout << "Flight information updated successfully." << endl;
            } else {
                cout << "Error opening file for writing." << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting admin menu..." << endl;
            return false; // Exit the admin menu
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void registerClient() {
    char username[50];
    char password[50];

    cout << "Enter a new username: ";
    cin.getline(username, 50);
    cout << "Enter a new password: ";
    cin.getline(password, 50);

    // Store username
    ofstream clientFile(client_file, ios::app); // Open file in append mode
    if (clientFile.is_open()) {
        clientFile << username << endl; // Store username
        clientFile.close();
    } else {
        cout << "Error opening client accounts file." << endl;
        return;
    }

    // Store password
    ofstream clientFilePassword(client_file_password, ios::app); // Open file in append mode
    if (clientFilePassword.is_open()) {
        clientFilePassword << password << endl; // Store password
        clientFilePassword.close();
        cout << "Account created successfully!" << endl;
    } else {
        cout << "Error opening client passwords file." << endl;
    }
}

// Function to log in an existing client
bool loginClient() {
    char username[50], password[50];
    cout << "Enter your username: ";
    cin.getline(username, 50);
    cout << "Enter your password: ";
    cin.getline(password, 50);

    ifstream clientFile(client_file);
    ifstream clientFilePassword(client_file_password);
    
    if (clientFile.is_open() && clientFilePassword.is_open()) 
	{
        char fileUsername[50];
        char filePassword[50];
        bool found = false;

        while (clientFile >> fileUsername)
		 {
            if (clientFilePassword >> filePassword)
			 {
                if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
                    found = true;
                    break; // Successful login
                }
            }
        }
        clientFile.close();
        clientFilePassword.close();

        if (found) {
            cout << "Login successful!" << endl;
            return true; // Successful login
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else {
        cout << "Error opening client accounts or passwords file." << endl;
    }
    return false; // Login failed
}


// Function to search for a flight
void searchFlight() {
    string searchTerm;
    cout << "Enter flight route to search (e.g., Karachi to Lahore): ";
    cin.ignore();
    getline(cin, searchTerm);
    
    ifstream myread("Flight Information.txt");
    if (myread.is_open()) {
        string line;
        bool found = false;
        cout << "\nSearch Results:\n";
        cout << "---------------------------------------------------------------------------------------------\n";
        while (getline(myread, line)) {
            // Check if the search term is found in the line
            if (line.find(searchTerm) != string::npos) {
                cout << line << endl; // Display complete flight information
                found = true;
            }
        }
        if (!found) {
            cout << "No flights found for: " << searchTerm << endl;
        }
        myread.close();
    } else {
        cout << "Error opening file." << endl;
    }
}

// Function to book a flight
void bookFlight() {
    string flightDetails;
    cout << "Enter flight details to book (e.g., Karachi to Lahore, Date, Name): ";
    cin.ignore();
    getline(cin, flightDetails);
    
    ofstream bookingFile(booking_file, ios::app); // Open file in append mode
    if (bookingFile.is_open()) {
        bookingFile << flightDetails << endl; // Save booking details
        bookingFile.close();
        cout << "Flight booked successfully!" << endl;
    } else {
        cout << "Error opening booking file." << endl;
    }
}

// Function to cancel a flight
void cancelFlight() {
    char bookings[MAX_BOOKINGS][line_length];
    int bookingCount = 0;

    ifstream bookingFile(booking_file);
    if (!bookingFile.is_open()) {
        cout << "Error opening booking file." << endl;
        return;
    }

    while (bookingFile.getline(bookings[bookingCount], line_length) && bookingCount < MAX_BOOKINGS) {
        bookingCount++;
    }
    bookingFile.close();

    if (bookingCount == 0) {
        cout << "No bookings found." << endl;
        return;
    }

    cout << "Current Bookings:\n";
    for (int i = 0; i < bookingCount; ++i) {
        cout << i + 1 << ". " << bookings[i] << endl;
    }

    int cancelChoice;
    cout << "Enter the number of the booking you want to cancel (1-" << bookingCount << "): ";
    cin >> cancelChoice;
    cin.ignore();

    if (cancelChoice < 1 || cancelChoice > bookingCount) {
        cout << "Invalid choice! Please select a valid booking number." << endl;
        return;
    }

    for (int i = cancelChoice - 1; i < bookingCount - 1; ++i) {
        strcpy(bookings[i], bookings[i + 1]);
    }
    bookingCount--;

    ofstream outFile(booking_file);
    if (outFile.is_open()) {
        for (int i = 0; i < bookingCount; ++i) {
            outFile << bookings[i] << endl;
        }
        outFile.close();
        cout << "Booking canceled successfully." << endl;
    } else {
        cout << "Error opening file for writing." << endl;
    }
}

// Function to display the client menu
void client_menu() {
    int choice;
    while (true) {
        cout << "\nClient Menu:\n"
             << "1. Register\n"
             << "2. Login\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        if (choice == 1) {
            registerClient(); // Call the function to register a new client
        } else if (choice == 2) {
            if (loginClient()) { // If login is successful
                while (true) {
                    cout << "\nFlight Options:\n"
                         << "1. Flight Details\n"
                         << "2. Book Flight\n"
                         << "3. Cancel Flight\n"
                         << "4. Exit\n"
                         << "Enter your choice: ";
                    int flightChoice;
                    cin >> flightChoice;
                    cin.ignore(); // Clear the newline character from the input buffer

                    if (flightChoice == 1) 
					{
                        flightDetails(); // Call the function to view flight details
                    } else if (flightChoice == 2) 
					{
                        bookFlight(); // Call the function to book a flight
                    } 
					else if (flightChoice == 3) 
					{
                        cancelFlight(); // Call the function to cancel a flight
                    } 
					else if (flightChoice == 4) 
					{
                        cout << "Exiting client menu..." << endl;
                        break; // Exit the client menu
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }
            }
        } else if (choice == 3) {
            cout << "Exiting the program..." << endl;
            break; // Exit the program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

// Main function
int main() {
    char expected_username[] = "Admin";
    char expected_password[] = "CPproject45";
    
    // Create flight information file if it doesn't exist
    createFlightInformationFile();

    cout << "\tWelcome to RHA Airline!" << "\n----------------------------------------\n\n";
    while (true) {
        cout << "Main Menu:\n"
             << "1. Admin Menu\n"
             << "2. Client Menu\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        int mainChoice;
        cin >> mainChoice;
        cin.ignore(); // Clear the newline character from the input buffer
        cout << "\n";

        if (mainChoice == 1) {
            if (login(expected_username, expected_password)) {
                cout << "Login successful!\n" << endl;
                if (!admin_menu()) {
                    continue; // Return to main menu after exiting admin menu
                }
            }
        } else if (mainChoice == 2) {
            client_menu(); // Call the client menu function
        } else if (mainChoice == 3) {
            cout << "Exiting the program..." << endl;
            break; // Exit the program
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}