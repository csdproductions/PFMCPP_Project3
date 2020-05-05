/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
*/

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
