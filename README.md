The 5th homework of OOP course 

We are building the Rush Hour game in compile time!

https://en.wikipedia.org/wiki/Rush_Hour_(puzzle)

In this project, we wish to get red car aka:"X X" to the right side of the board.

In a given board, it will solve the game in minimal number of moves and will print every change in the board.

Car types: 

![alt text](https://github.com/Gil16/RushHourGame-CompileTime/blob/master/car_types.PNG?raw=true)



Example:
```
Game Board:
 _ _ _ R _ _
 _ _ _ R _ _
 _ X X R _ P
 _ C D D _ P
 _ C _ _ _ P
 _ _ _ _ F F

Game Board:
 _ _ _ R _ _
 _ _ _ R _ _
 _ X X R _ P
 _ _ D D _ P
 _ C _ _ _ P
 _ C _ _ F F

Game Board:
 _ _ _ R _ P
 _ _ _ R _ P
 _ X X R _ P
 _ _ D D _ _
 _ C _ _ _ _
 _ C _ _ F F

Game Board:
 _ _ _ R _ P
 _ _ _ R _ P
 _ X X R _ P
 _ _ _ _ D D
 _ C _ _ _ _
 _ C _ _ F F

Game Board:
 _ _ _ _ _ P
 _ _ _ _ _ P
 _ X X _ _ P
 _ _ _ R D D
 _ C _ R _ _
 _ C _ R F F

Game Board:
 _ _ _ _ _ P
 _ _ _ _ _ P
 _ _ X X _ P
 _ _ _ R D D
 _ C _ R _ _
 _ C _ R F F

Game Board:
 _ C _ _ _ P
 _ C _ _ _ P
 _ _ X X _ P
 _ _ _ R D D
 _ _ _ R _ _
 _ _ _ R F F

Game Board:
 _ C _ _ _ P
 _ C _ _ _ P
 _ X X _ _ P
 _ _ _ R D D
 _ _ _ R _ _
 _ _ _ R F F

Game Board:
 _ C _ R _ P
 _ C _ R _ P
 _ X X R _ P
 _ _ _ _ D D
 _ _ _ _ _ _
 _ _ _ _ F F

Game Board:
 _ C _ R _ P
 _ C _ R _ P
 _ X X R _ P
 D D _ _ _ _
 _ _ _ _ _ _
 _ _ _ _ F F

Game Board:
 _ C _ R _ P
 _ C _ R _ P
 _ X X R _ P
 D D _ _ _ _
 _ _ _ _ _ _
 F F _ _ _ _

Game Board:
 _ C _ R _ _
 _ C _ R _ _
 _ X X R _ _
 D D _ _ _ P
 _ _ _ _ _ P
 F F _ _ _ P

Game Board:
 _ C _ _ _ _
 _ C _ _ _ _
 _ X X _ _ _
 D D _ R _ P
 _ _ _ R _ P
 F F _ R _ P
```
