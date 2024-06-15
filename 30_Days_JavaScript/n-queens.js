function solveNQueens(n) {
  // Create an empty board
  const board = new Array(n).fill(new Array(n).fill(0));

  // Recursively solve the problem
  if (solveNQUtil(board, 0)) {
    // If a solution is found, print the board
    printBoard(board);
    return true;
  } else {
    // If no solution is found, return false
    return false;
  }
}

// Check if a queen can be placed at a given position
function isSafe(board, row, col) {
  // Check if there is a queen in the same row
  for (let i = 0; i < col; i++) {
    if (board[row][i] === 1) {
      return false;
    }
  }

  // Check if there is a queen in the same column
  for (let i = 0; i < row; i++) {
    if (board[i][col] === 1) {
      return false;
    }
  }

  // Check if there is a queen in the same diagonal
  for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] === 1) {
      return false;
    }
  }

  // Check if there is a queen in the same anti-diagonal
  for (let i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
    if (board[i][j] === 1) {
      return false;
    }
  }

  // If no queen is found in any of the above positions, then the position is safe
  return true;
}

// Place a queen at a given position and recursively solve the problem
function solveNQUtil(board, col) {
  // If all queens are placed, return true
  if (col >= n) {
    return true;
  }

  // Try placing a queen in each row of the current column
  for (let i = 0; i < n; i++) {
    if (isSafe(board, i, col)) {
      // Place the queen
      board[i][col] = 1;

      // Recursively solve the problem for the next column
      if (solveNQUtil(board, col + 1)) {
        return true;
      }

      // If no solution is found, remove the queen
      board[i][col] = 0;
    }
  }

  // If no solution is found in the current column, return false
  return false;
}

// Print the board
function printBoard(board) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      console.log(board[i][j] + " ");
    }
    console.log();
  }
}

// Solve the N-Queens problem for n = 4
solveNQueens(4);
