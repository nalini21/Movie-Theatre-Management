# Movie-Theatre-Management-in-C++
<h2>Movie Ticket Reservation Application</h2>

We all have booked movie tickets using numerous ticket booking apps/websites
available today. This question requires developers to build an application which
achieves this functionality.

<h3>1. Add a screen</h3>
Ability to register a screen
a. screen name
b. number of rows
c. total seats per row
d. list of aisle seats for each row

screen name is primary identifier.

Format for command for adding a screen:
<h4>add-screen <screen-name> <number-of-rows> <total-seats-per-row> <space seperated list of aisle seats></h4>
eg:
add-screen Screen1 12 10 4 5 8 9
This command registers a screen with name 'Screen1' which has 12 rows with 10 seats each.
Seat numbers 4, 5, 8 and 9 are aisle seats.
Response format:
success -> if the request is successful
failure -> if the result fails

<h3>2. Reserve seats</h3>
Ability to reserve seats in a screen if they are available

Fomat for command for reserving seats:
<h4>reserve-seat <screen-name> <row-number> <space seperated list of seats to be reserved></h4>
eg:
reserve-seat Screen1 4 5 6 7
This command reserves seats in 'Screen1' row 4, seats 5, 6 and 7 if they are not already reserved
and are not aisle seats.
Response format: 
Success -> if the request is successful
failure -> if the request fails

<h3>3. Get unreserved seats for a row</h3>
Ability to fetch unreserved seats for a row in a given screen

Format for command for getting unreserved seats:
<h4>get-unreserved-seats <screen-name> <row-number></h4>
eg:
get-unreserved-seats Screen1 4
This command returns the list of unreserved seats in 'Screen1' in row 4
Response format:
1 2 3 4 8 9 10

<h3>4. Suggest seats based on user preference</h3>
This command suggest contiguous seat numbers based on user's preference. This functionality
should take into account aisle seats as well since that will decide if contiguous seats are
possible for the user's choice. If no contiguous comination is possible, the response should
specify that it is not feasible to fulfil the request. This functionality should also take into
account reserved seats based on functionality 2

Format for the command to get seat suggestion:
<h4>suggest-contiguous-seats <screen-name> <number of seats> <row-number> <choice-of-seat-number></h4>
eg:
suggest-contiguous-seats Screen1 3 3 4
This command returns list of 3 contiguous seats from row 3 from 'Screen1' either starting or
ending with seat number 4. If no such combination exists, the response should be 'none'
Response format:
2 3 4
If no seat combination exists:
none



//sample input
9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguous-seats Screen2 4 10 3

//corresponding output
success
success
success
success
failure
1 2 3 4 5 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
2 3 4
4 5 6 7
none

