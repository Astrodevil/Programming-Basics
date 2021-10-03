package kshitizjava;
/*
 * Given a string s consisting of some words 
 * separated by some number of spaces, 
 * return the length of the last word in the string.
 * 
 * for example Hello World
 * will give 5
 * as The last word is "World" with length 5.
 * 
 */
import java.util.*;
public class last_word {

	    public static int lengthOfLastWord(String s) {
	        
	        String S=s.trim();
	        int l=S.length();
	        String str="";
	        int p=0;
	        
	        for(int i=l-1;i>0;i--)
	        {
	            if(S.charAt(i)==' ')
	            {
	                p=i+1;
	                break;
	            }
	            
	            
	        }
	        str=S.substring(p,l);
	        int l2=str.length();
	        return l2;
	        
	    }

	public static void main(String[] args) {
		Scanner in=new Scanner (System.in);
		System.out.println("Enter a String");
		String s=in.nextLine();
		System.out.println(last_word.lengthOfLastWord(s));

	}

}
