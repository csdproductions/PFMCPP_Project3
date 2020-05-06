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

/*
3) Bicycle
5 properties:
    1) frame
    2) wheels
    3) brakes
    4) pedals
    5) handlebars
3 things it can do:
    1) move forwards
    2) bunny hop
    3) wheelie
 */

/*
4) Electric Guitar
5 properties:
    1) body
    2) neck
    3) strings
    4) pickups
    5) frets
3 things it can do:
    1) output sound
    2) change tone
    3) change pickup
 */

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

/*
6) program (male, female, or junior team)
5 properties:
    1) sex
    2) age range
    3) professional status
    4) number of staff
    5) total number of programs
3 things it can do:
    1) enter a league
    2) determine player's program
    3) advertise for players
 */

/*
7) Training Complex
5 properties:
    1) reception
    2) canteen
    3) gym
    4) locker room
    5) car Park
3 things it can do:
    1) host training session
    2) feed staff
    3) provide player rehab
 */

/*
8) Stadium
5 properties:
    1) seats
    2) bars
    3) gates
    4) executive boxes
    5) staircases
3 things it can do:
    1) host an event
    2) open gates
    3) sell food
 */

/*
9) Supporters
5 properties:
    1) total number
    2) location
    3) distance from club's city
    4) member of supporters group
    5) cheer team
3 things it can do:
    1) join supporters group
    2) buy jersey
    3) go to away match
 */

/*
10) Sports Team
5 properties:
    1) staff
    2) program
    3) training complex
    4) stadium
    5) supporters
3 things it can do:
    1) play a match
    2) run a training session
    3) sign a player
 */

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
