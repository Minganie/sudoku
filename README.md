# Sudoku
This is a personal project to keep me occupied during free time. As the title suggests, it revolves around the sudoku game; in time, it will be a sudoku solver, generator and helper.
##Motivation
I've been a sudoku player for a long time now, and I've wondered for years how people generate new sudoku grids. It's not a simple matter of starting from a full grid and hollowing a certain number of squares; if one proceeded like that, there would be no guarantee that the grid has a unique solution and is solvable by a human without taking guesses.

I've also seen detailed tutorials on sudoku techniques on the internet and thought it would be really nice when stumped on a grid if someone could give you a hint, not a spoiler, by pointing out which technique is applicable on the grid at hand.

I started this project as a way to study these problems.
##Milestones
###Solver
(I am here now.)

I read that generating new unique-solution grids is usually done by starting with a full grid and, hollowing one square at a time, checking every time that the resulting grid has only one solution using a backtracking algorithm. Therefore, a functionning sudoku solver using the backtracking algorithm is the first step in my project.
###Generator
The second step which naturally follows the solver is to produce new unique-solution grids. This could eventually be extended to produce new grids of different difficulty levels, but that might be easier to accomplish once the helper (next milestone) is complete.
###Helper
The third step, which will certainly amount to a lot more work, is a sudoku helper that is able to not only check if there are mistakes in a current grid, but also point out which techniques are available in the current grid.
###Performance
At this point, I should probably start studying performance metrics because rule of thumb says all this will require **a lot** of iterating through grid squares. This will be a great occasion to learn about profilers, which I've never used before.
###GUI
Once all the internal workings are in place, it would be sad to have done all this work for a console application that not a single real-world user would want to use. This will be a great occasion to learn about graphic interfaces, which I've only done in HTML so far. Since the project is C++, I'm thinking of getting some hands-on experience with Qt.
##Reference materials
Giving credit where credit is due, the reference materials I use are listed in [the wiki](https://github.com/Minganie/sudoku/wiki).
