/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Create a branch named Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct for each of your 10 types. i.e.:
*/
struct CellPhone
{

};
/*
2) Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


/*
1) Games Console
5 properties:
    1) control pads
    2) disc drive
    3) usb ports
    4) hdmi outputs
    5) network connection
3 things it can do:
    1) read discs
    2) play games
    3) connect to network
 */

struct GamesConsole
{

    //control pads
    int noOfControlPads = 2;
    // storage drive size
    float storageDriveSize = 128.f;
    // usb ports
    int noOfUsbPorts = 4;
    // hdmi outputs
    int noOfHdmiOutputs = 3;
    // network connections
    int networkConnection = 2;

    // read discs
    void readDisc(std::string gameDisc = "Grand Theft Auto");
    // play games
    void playGame(int noOfPlayers = 8);
    // connect to network - return if connection successful
    bool connectToNetwork(float connectionSpeed = 1000.f);
};

/*
2) Dog
5 properties:
    1) fur colour
    2) age
    3) breed
    4) name
    5) sex
3 things it can do:
    1) fetch
    2) sit
    3) heel
 */

struct Dog
{
    //fur colour
    std::string furColour = "Brown";
    //age
    float age = 1.f;
    //breed
    std::string breed = "Shih-Tzu";
    //name
    std::string name = "Luna";
    //sex
    std::string sex = "Female";

    //fetch 
    void fetch(std::string ballType = "Tennis");
    //sit
    void sit(std::string treatType = "Peanut Butter");
    //heel
    void heel();
};

/*
3) Bicycle
5 properties:
    1) frame size
    2) wheel size
    3) brakes model
    4) pedals type
    5) handlebars type
3 things it can do:
    1) move forwards
    2) bunny hop
    3) wheelie
 */

struct Bicycle
{
    //frame size
    float frameSize = 51.1f;
    //wheel size
    float wheelRimSize = 18.f;
    //brakes model
    std::string brakesModel = "Shimano";
    //pedals type (1 for standard, 2 for cleats)
    int pedalsType = 1;
    //handlebars type (1 for drops, 2 for straight)
    int handlebarsType = 1;

    //move forwards - return 
    float moveForwards();
    //bunny hop - return height
    float bunnyHop();
    //wheelie
    bool popWheelie();
};

/*
4) Electric Guitar
5 properties:
    1) body wood
    2) is neck joint glued
    3) high e string gauge
    4) pickups type
    5) no of frets 
3 things it can do:
    1) output sound
    2) change tone
    3) change pickup
 */

struct ElectricGuitar{

    //body wood - 1 = maple, 2 = oak
    int bodyWood = 1;
    //neck joint glued
    bool neckJointGlued = false;
    //strings gauge
    int eStringGauge = 13;
    //pickups type
    std::string pickupsType = "Humbucker";
    //no of frets 
    int noOfFrets = 24;

    //output sound
    void outputSound(int fretPlayed);
    //change tone - return tone resistance value
    float changeTone(bool isSoloNow);
    //change pickup - return
    int selectPickup(int songStyle);
};


/*
5) Staff
5 properties:
    1) type
    2) sex
    3) age
    4) hours of work
    5) days of work
3 things it can do:
    1) go to work
    2) attend meeting
    3) sign a contract
 */

 struct Staff{

    //type
    std::string type = "Player";
    //sex
    std::string sex = "Male";
    //age
    int age = 22;
    //hours of work
    float hoursOfWork = 37.5f;
    //days of work
    int daysOfWork = 5;

    //go to work
    void goToWork();
    //attend meeting
    void attendMeeting();
    //sign a contract
    bool signContract(float contractOffer = 20000.f);
 };

/*
6) program (male, female, or junior team)
5 properties:
    1) sex
    2) maximum age
    3) professional status
    4) number of staff
    5) total number of programs
3 things it can do:
    1) enter a league
    2) determine player's program
    3) advertise for players
 */

struct TeamProgram
{
    //sex
    std::string sex = "Male";
    //maximum age
    int maxAge = 21;
    //professional status
    std::string profStatus = "Semi-Professional";
    //number of staff
    int noOfStaff = 6;
    //total number of programs
    int totalNoOfPlayers = 22;


    //enter a league
    void enterALeague();
    //determine player's program
    void playersProgram();
    //advertise for players
    void advertiseForPlayers(int howManySpacesLeft = 4);
};

/*
7) Training Complex
5 properties:
    1) receptionist of the day
    2) no of meals served in canteen a day
    3) maximum deadlift weight in gym
    4) no of lockers in locker room
    5) no of car park spots
3 things it can do:
    1) host training session
    2) feed staff
    3) provide player rehab
 */

struct TrainingComplex
{

    //receptionist of the day
    std::string receptionistName = "Dave";
    //no of meals served in canteen a day
    int noOfMealsServed = 122;
    //maximum deadlift weight in gym
    float maxDeadliftWeight = 500.f;
    //no of lockers in locker room
    int noOfLockers = 100;
    //no of car park spots
    int noOfCarParkSpots = 75;

    //host training session
    void hostTrainingSession();
    //feed staff
    void feedStaff(int howManyStaffWorkingToday = 75);
    //provide player rehab
    void providePlayerRehab(Staff player);
};


/*
8) Stadium
5 properties:
    1) capacity
    2) name
    3) turf type
    4) bool executive boxes open
    5) staircase names
3 things it can do:
    1) host an event
    2) open gates
    3) restock a concession stand
 */

struct Stadium
{
    //capacity
    int noOfSeats = 44000;
    //stadium name
    std::string name = "Paul Brown Stadium";
    //turf type (1 = grass, 2 = turf)
    int turfType = 1;
    //are executive boxes open
    bool boxesOpen = true;
    //no of staircases
    int noOfStaircases = 22;

    struct ConcessionStand
    {
        //stand type (1 for food/drink, 2 for merchandise)
        int standType = 1;
        //does it have a liqour license
        bool liquorLicense = false;
        //min no of staff required to run it
        int minNoOfStaff = 6;
        //max no of staff required
        int maxNoOfStaff = 8;
        //name of stand
        std::string name = "Dave's magical hot-dogs";

        //check customer ID
        bool isCustomerOfAge(int customerAge = 22);
        //display which customer order will be ready next
        int displayNextReadyCustomerOrders();
        //take order from customer
        void takeCustomerOrder();
    };
    
    //host an event
    void hostAnEvent();
    //open gates
    void openGates();
    //restock a concession stand
    void restockConcessionStand(ConcessionStand myConcessionStand);

    ConcessionStand myConcessionStand;
};


/*
9) Supporter Group
5 properties:
    1) name
    2) no of members
    3) no of season tickets
    4) merch discount from club
    5) cost of membership
3 things it can do:
    1) arrange trip to away match
    2) add a new member
    3) email a member on their birthday
 */

struct SupportersGroup
{
    std::string name = "Queen City Hooligans";
    int noOfMembers = 120;
    int noOfSeasonTickets = 60;
    float merchDiscountFromClub = 10.f;
    float costOfMembership = 100.f;

    struct Supporter
    {
        //jersey size
        std::string jerseySize = "M";
        //location
        std::string whereDoYouLive = "Cincinnati";
        //distance from club's city
        float distanceFromClubsCity = 123.f;
        //season ticket holder
        bool seasonTicketHolder = false;
        //no of meetings attended
        int noOfMeetingsAttended = 3;

        // join supporters group
        void joinSupportersGroup();
        // buy jersey
        void buyJersey();
        // go to away match
        void goToAwayMatch(std::string awayCity = "Salt Lake");
    };

    //Arrange trip to away match
    void organiseAwayMatchTrip(int noOfSupporters = 20);
    //Add a new member
    void admitNewMember(Supporter mySupporter);
    //Email a member on their birthday
    void emailMemberOnBirthday(Supporter mySupporter);

    Supporter mySupporter;
};


/*
10) Sports Team
5 properties:
    1) staff
    2) program
    3) training complex
    4) stadium
    5) supporter
3 things it can do:
    1) play a match
    2) run a training session
    3) sign a player
 */

 struct SportsTeam
 {
    // staff
    Staff staffMember;
    // program
    TeamProgram program;
    //training complex
    TrainingComplex complex;
    //stadium
    Stadium stadium;
    //supporter
    SupportersGroup mySupportersGroup;

    // play a match
    void playMatch(TeamProgram, Stadium);
    // run a training session
    void runTrainingSession(TeamProgram, TrainingComplex);
    // sign a player
    bool signAPlayer(Staff);
 };

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
