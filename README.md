# SudokuSolver
This is a project of very famous game called Sudoku Solver coded in C++<br/>
Sudoku is one of the very famous  puzzle in which players insert the numbers one to nine into a grid consisting of nine squares subdivided into a further nine smaller squares in such a way that every number appears once in each horizontal line, vertical line, and square.<br/>
This project has required configurations:<br/>
1:VS Code <br/>
2:clang or any other c++ compiler must be installed in your sytem.<br/>
NOTE: You can use any other editor or C++ IDE like Clion,Sublime text etc.<br/>
The SudokuSolver.cpp contains following functions:<br/>
1: main():the whole program will run from this function.In this function a 9x9 array is inputted by the user and it will be passed to SudokuSolver function
.If the matrix  is valid then it will display the required sudoku othewise it wil display "No solution exist"<br/>
2:SudokuSolver():This is the most important funcion which will return whether the inputted matrix is valid or not.The approach is to traverse through all the  elements of the matrix .If the element is nonzero the continously go to another element in the same row .If the element is 0 then check whether the following conditions for the element  are true or not:<br/>
(a):There should be no same element at that particluar row in the matrix.<br/>
(b):There should be no same element at that particluar column in the matrix.<br/>
(c):There should be no same element at 3x3 non overlapping submatrix(subgrid) of the  matrix.<br/>
3:All the above three conditions will be checked by the function isValid() .If all the conditions are true it will return true otherwise false<br/>
isValid():This function will run 3 loops i.e for rows,columns,subgrid respectively .It will check every index of that particular row or column or subgrid ,whether is there any element that matches with the required element.To reach a particular submatrix we will divide that row and column index by 3 and then multiply it with 3 and store them in smi and smj variables respectively .After we will traverse every arr[smi+i][smj+j]index and check if there is a  particular element present or not.<br/>
Since there might be a case that we have inputted a number intially and after reaching deeply through the matrix there might be case where isValid return false.So for this we have to remove that particular number from that index when our stack was falling through recursion.Then we will return back to elements that we have filled and check all other numbers from 1 to 9 instead of that particluar number.This concept is  also called bactracking.<br/>
Since we are applying Recursion concept with Backtracking,so there must be a base case.The base case will be when the control reaches to 10 row i.e 9 index of row then we will return true which will then display the array consisting of all the correctly filled numbers in following all the rules of Sudoku.<br/>
If the SudokuSolver() function return false then there must no solution exits of the array.So it will display "No solution Exists".<br/>
