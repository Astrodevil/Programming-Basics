import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ConnectFour 
{

  private static final char[] PLAYERS = {'X','O'};
  private final int width, height;
  private final char[][] grid;
  private int lastCol = -1, lastTop = -1;
  public ConnectFour(int w, int h) 
  {
    width = w;
    height = h;
    grid = new char[h][];
    for (int i = 0; i < h; i++) 
    {
      Arrays.fill(grid[i] = new char[w], '.');
    }
  }
  public String toString() 
  {
     return IntStream.range(0,  width).
           mapToObj(Integer::toString).
           collect(Collectors.joining()) + 
           "\n" +
           Arrays.stream(grid).
           map(String::new).
           collect(Collectors.joining("\n"));
  }
  public String horizontal() 
  {
    return new String(grid[lastTop]);
  }
  public String vertical() 
  {
    StringBuilder sb = new StringBuilder(height);

    for (int h = 0; h < height; h++) 
    {
      sb.append(grid[h][lastCol]);
    }

    return sb.toString();
  }
  public String slashDiagonal() 
  {
    StringBuilder sb = new StringBuilder(height);

    for (int h = 0; h < height; h++) 
    {
      int w = lastCol + lastTop - h;

      if (0 <= w && w < width) 
      {
        sb.append(grid[h][w]);
      }
    }
    return sb.toString();
  }
  public String backslashDiagonal() 
  {
    StringBuilder sb = new StringBuilder(height);

    for (int h = 0; h < height; h++) 
    {
      int w = lastCol - lastTop + h;

      if (0 <= w && w < width) 
      {
        sb.append(grid[h][w]);
      }
    }
    return sb.toString();
  }
  public static boolean contains(String str, String substring) 
  {
    return str.indexOf(substring) >= 0;
  }
  public boolean isWinningPlay() {
    if (lastCol == -1) 
    {
      System.err.println("No move has been made yet");
      return false;
    }
    char sym = grid[lastTop][lastCol];
    String streak = String.format("%c%c%c%c", sym, sym, sym, sym);
    return contains(horizontal(), streak) || 
           contains(vertical(), streak) || 
           contains(slashDiagonal(), streak) || 
           contains(backslashDiagonal(), streak);
  }
  public void chooseAndDrop(char symbol, Scanner input) 
  {
    do 
    {
      System.out.println("\nPlayer " + symbol + " turn: ");
      int col = input.nextInt();
      if (!(0 <= col && col < width)) 
      {
        System.out.println("Column must be between 0 and " + (width - 1));
        continue;
      }
      for (int h = height - 1; h >= 0; h--) 
      {
        if (grid[h][col] == '.') {
          grid[lastTop = h][lastCol = col] = symbol;
          return;
        }
      }
      System.out.println("Column " + col + " is full.");
    } while (true);
  }
  public static void main(String[] args) 
  {
    System.out.println("                       ---------------------------");
    System.out.println("                       Welcome to ConnectFour Game");
    System.out.println("                       ---------------------------");
    System.out.println("The first to form a horizontal, vertical, or diagonal line of four of one’s own discs wins.");
    System.out.println("               X stands for Player 1 and O stands for Player 2");
    System.out.println("                       Then let's begin the game!!!");
      try (Scanner input = new Scanner(System.in)) 
    {
      int height = 6; int width = 8; int moves = height * width;
      ConnectFour board = new ConnectFour(width, height);
      System.out.println("Use 0-" + (width - 1) + " to choose a column");
      System.out.println(board);
      for (int player = 0; moves-- > 0; player = 1 - player) 
      {
        char symbol = PLAYERS[player];
        board.chooseAndDrop(symbol, input);
        System.out.println(board);
        if (board.isWinningPlay()) 
        {
          System.out.println("\nPlayer " + symbol + " wins!");
          return;
          
        }
      }
      System.out.println("Game over. No winner. Try again!");
    }
  }

}