import java.util.*;
public class PigLatin
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the word");
        String s=sc.nextLine();
        String str=s.toUpperCase();
        int x=str.length();
        int y;
        char b=0;
        System.out.println("The Pig latin of the given word is ");
        for(y=0;y<x;y++)
        {
            b=(str.charAt(y));
            if((b=='A')||(b=='E')||(b=='I')||(b=='O')||(b=='U'))
            break;
        }
        String str1=str.substring(y,x);
        String str2=str.substring(0,y);
        System.out.println(str1+str2+"AY");
    }
}