import java.util.Scanner;
public class string_methods {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(s.length());
        System.out.println(s.toUpperCase());
        System.out.println(s.toLowerCase());
        System.out.println(s.substring(3));
        System.out.println(s.substring(2,4));
        System.out.println(s.replace('S','r'));
        System.out.println(s.startsWith("s"));
        System.out.println(s.endsWith("m"));
        System.out.println(s.charAt(3));
        System.out.println(s.indexOf("i"));

    }
}
