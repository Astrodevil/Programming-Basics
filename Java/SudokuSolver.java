// import java.io.*;
import java.util.*;

public class SudokuSolver {
  public static void display(int[][] board){
    for(int i = 0; i < board.length; i++){
      for(int j = 0; j < board[0].length; j++){
        System.out.print(board[i][j] + " ");
      }
      System.out.println();
    }
  }

  public static void solveSudoku(int[][] board, int i, int j) {
    // write yopur code here
    if(i==9){
        display(board);
        return;
    }
    
    int nc;
    int nr;
    if(j==board.length-1){
        nc=0;
        nr=i+1;
    }else{
        nr=i;
        nc=j+1;
    }
    
    
    if(board[i][j]==0){
        for(int val=1;val<=9;val++){
            
            if(isSafe(board,i,j,val)==true){
                board[i][j]=val;
                 solveSudoku(board,nr,nc);
                 board[i][j]=0;
            }
        }
    }else{
      
          solveSudoku(board,nr,nc);
        
    }
    
    
    
  }
  
  
  public static boolean isSafe(int[][] board,int row,int col,int val){
      
      for(int i=0,j=col;i<board.length;i++){
          if(board[i][col]==val){
              return false;
          }
      }
      
      for(int j=0,i=row;j<board.length;j++){
          if(board[i][j]==val){
              return false;
          }
      }
      
      int sr=(row/3)*3;
      int sc=(col/3)*3;
      
      for(int r=sr;r<=sr+2;r++){
          for(int c=sc;c<=sc+2;c++){
              if(board[r][c]==val){
                  return false;
              }
          }
      }
      
      
      return true;
  }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int[][] arr = new int[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        arr[i][j] = scn.nextInt();
      }
    }

    solveSudoku(arr, 0, 0);
  }
}