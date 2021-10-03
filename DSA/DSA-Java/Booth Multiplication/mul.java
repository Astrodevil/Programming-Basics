/**
 * Write a description of mul here.
 * 
 * @author Sushant Sinha
 * @version v1.0.0
 */

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.scene.paint.Color;
import javax.swing.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class mul extends Application {

    public static void main(String[] args) {
        launch(args);
    }
    
    @Override
    public void start(Stage primaryStage) throws Exception {

        GridPane root = new GridPane();
        GridPane output = new GridPane();
        Button btn = new Button("Multiply");

        btn.setStyle(
            "-fx-background-radius: 5em; " +
            "-fx-min-width: 90px; " +
            "-fx-min-height: 90px; " +
            "-fx-max-width: 90px; " +
            "-fx-max-height: 90px;"
        );

        Button exit = new Button("Exit");

        exit.setTextFill(Color.WHITE);

        exit.setStyle(
            "-fx-background-color: #af0000;"+
            "-fx-background-radius: 5em; " +
            "-fx-min-width: 90px; " +
            "-fx-min-height: 90px; " +
            "-fx-max-width: 90px; " +
            "-fx-max-height: 90px;"
        );

        Text t1 = new Text("Multiplicand: ");
        Text t2 = new Text("Multiplier: ");
        TextField multiplicand = new TextField();
        TextField multiplier = new TextField();
        TextArea result=new TextArea();
        result.setPrefWidth(1000);        
        result.setPrefHeight(500);
        result.setEditable(false);
        
        Scene scene = new Scene(root, 1500, 800);
        Scene scene1 = new Scene(output, 1500, 800);
        
        root.setHgap(17);
        root.setVgap(20);
        root.add(btn, 25, 20);
        root.add(t1, 20, 17);
        root.add(t2, 30, 17);
        root.add(multiplicand, 22, 17);
        root.add(multiplier, 32, 17);

        output.setHgap(15);
        output.setVgap(50);
        output.add(result,20,4);
        output.add(exit,22,4);
        
        primaryStage.setScene(scene);
        primaryStage.setTitle("BOOTH MULTIPLIER");
        primaryStage.show();

        // action events

        btn.setOnAction(new EventHandler < ActionEvent > () {



            @Override
            public void handle(ActionEvent arg0) {

                int m1 = Integer.parseInt(multiplicand.getText());
                int m2 = Integer.parseInt(multiplier.getText());

                String m = getbinary(m1);
                result.setText(result.getText()+m1 +", the multiplicand in signed 2s complement notation is " +m+"\n");

                String r = getbinary(m2);
                result.setText(result.getText()+m2 +", the multiplier in signed 2s complement notation is " +r);
                int x = m.length();
                int y = r.length();
                result.setText("\n"+result.getText()+"\n-------------------------------------------------------------------------");
                // determining initial values of A,S and P

                if (m1 * m2 > 32767 || m1 * m2 < -32768) { // -2^15 < product < 2^15-1 for a 16 bit register
                    result.setText("\n"+result.getText()+"Product is out of range for a 16-bit register!!");
                    return;
                }

                String A = m;
                for (int i = 0; i <= y; i++) {
                    A = A + "0";
                }

                result.setText(result.getText()+"\n\nThe initial value of BR (with appended zeroes for ease of addition) is " + A);

                String S = get2scomplement(m.substring(1));

                if (m1 <= 0) {
                    S = "0" + S;
                }
                
                else{
                    S = "1" + S;
                }

                for (int i = 0; i <= y; i++) {
                    S = S + "0";
                }
                result.setText(result.getText()+"\n\nThe initial value of 2's complement of BR represented by BR'+1(with appended zeroes for ease of addition) is " + S);

                String P = "";
                for (int i = 0; i < x; i++) {
                    P += "0";
                }
                P = P + r + "0";
                result.setText(result.getText()+"\n\nThe initial value of AC+QR+Q(n+1) is " + P);
                result.setText(result.getText()+"\n-------------------------------------------------------------------------");
                for (int i = y; i >0; i--) {

                    if (P.substring(P.length() - 2).equals("01")) {
                        P = binaryaddn(P, A);
                        P = shiftright(P);
                        result.setText(result.getText()+"\nThe value of    AC+QR+Q(n+1)    after          AC+QR+Q(n+1) + BR operation and right shift is                  " + P + "          for SC = " + i);
                    }
                    
                    else if (P.substring(P.length() - 2).equals("10")) {
                        P = binaryaddn(P, S);
                        P = shiftright(P);
                        result.setText(result.getText()+"\nThe value of    AC+QR+Q(n+1)    after          AC+QR+Q(n+1) +  + BR'+1 operation and right shift is        " + P + "          for SC = " + i);
                    }
                    
                    else {
                        P = shiftright(P);
                        result.setText(result.getText()+"\nThe value of    AC+QR+Q(n+1)    after          right shift is                                                                             " + P +"          for SC = " + i);
                    }
                }

                P = P.substring(0, P.length() - 1);
                result.setText(result.getText()+"\n-------------------------------------------------------------------------");

                result.setText(result.getText()+"\nThe product of the numbers entered in binary is " +P);
                if (P.charAt(0) == '0') {
                    result.setText(result.getText()+"\nIt's Decimal Equivalent is ");
                    
                    Long n = Long.parseLong(P);
                    Long rem = (long) 0;
                    Long ans = (long) 0;
                    Long val = (long) 1;
            
                    while (n != 0) {
                        rem = n % 10;
                        ans = ans + rem * val;
                        n = n / 10;
                        val = val * 2;
                    }
                    
                    result.setText(result.getText()+ans);
                    int i;
                    for (i = 0; i < P.length(); i++) {
                        if (P.charAt(i) == '0') { // leftmost zeroes are removed to get decimal eqv to avoid redundancy 
                            continue;
                        }
                        break;
                    }
                    if (i == P.length()) { // this means that the string consists of zeroes only.
                        // checking for 0
                        result.setText(result.getText()+"0");

                        return;
                    }
                    binarytodec(P.substring(i)); // after removing leading zeroes
                }

                if (P.charAt(0) == '1') {
                    result.setText(result.getText()+"\nMSB = 1 indicates that the given number is negative." +" It's magnitude is given by the magnitude of it's 2's complement, that is ");
                    String comp=get2scomplement(P);
                    Long n = Long.parseLong(comp);
                    Long rem = (long) 0;
                    Long ans = (long) 0;
                    Long val = (long) 1;
            
                    while (n != 0) {
                        rem = n % 10;
                        ans = ans + rem * val;
                        n = n / 10;
                        val = val * 2;
                    }
                    
                    result.setText(result.getText()+ans);
                 
                                    
                }
                
                primaryStage.setScene(scene1);
                primaryStage.setTitle("BOOTH MULTIPLIER");
                primaryStage.show();

            }

        });
        
        exit.setOnAction(new EventHandler < ActionEvent > () {

            @Override
            public void handle(ActionEvent arg0) {

                System.exit(0);

            }

        });
    }
        
    static String get2scomplement(String s1) {

        String s2 = "";
        for (int i = 0; i < s1.length(); i++) { // flipping the bits

            if (s1.charAt(i) == '0') {
                s2 += '1';
                continue;
            }
            s2 += '0';
        }

        String s3 = "";
        String carry = "1";
        for (int i = s2.length() - 1; i >= 0; i--) {

            if (s2.charAt(s2.length() - 1) == '0') {
                s2 = s2.substring(0, s2.length() - 1) + "1";
                return s2;
            }

            if (s2.charAt(i) == '1' && carry.equals("1")) {
                s3 = '0' + s3;
                carry = "1";
            } else if (s2.charAt(i) == '0' && carry.equals("1")) {
                s3 = '1' + s3;
                carry = "0";
            } else if (s2.charAt(i) == '0' && carry.equals("0")) {
                s3 = '0' + s3;
                carry = "0";
            } else {
                s3 = '1' + s3;
                carry = "0";
            }

        }

        return s3;

    }

    public static String getbinary(int n) {

        String str1 = "";

        if (n >= 0) {

            str1 = Integer.toBinaryString(n);
            str1 = "0" + str1;
        } else {
            str1 = Integer.toBinaryString(-1 * n);
            str1 = get2scomplement(str1);
            str1 = "1" + str1;
        }
        return str1;

    }

    public static String shiftright(String str) {

        return str.charAt(0) + str.substring(0, str.length() - 1);

    }

    public static String binaryaddn(String s1, String s2) {

        String res = "";
        String carry = "0";
        for (int i = s1.length() - 1; i >= 0; i--) {

            if (s1.charAt(i) == '1' && s2.charAt(i) == '1' && carry.equals("0") ||
                (s1.charAt(i) == '0' && s2.charAt(i) == '1' &&
                    carry.equals("1")) || s1.charAt(i) == '1' &&
                s2.charAt(i) == '0' && carry.equals("1")) {
                res = '0' + res;
                carry = "1";
            } else if (s1.charAt(i) == '1' && s2.charAt(i) == '1' &&
                carry.equals("1")) {
                res = '1' + res;
                carry = "1";
            } else if (s1.charAt(i) == '0' && s2.charAt(i) == '1' &&
                carry.equals("0") || s1.charAt(i) == '1' &&
                s2.charAt(i) == '0' && carry.equals("0") ||
                s1.charAt(i) == '0' && s2.charAt(i) == '0' &&
                carry.equals("1")) {
                res = '1' + res;
                carry = "0";
            } else if (s1.charAt(i) == '0' && s2.charAt(i) == '0' &&
                carry.equals("0")) {
                res = '0' + res;
                carry = "0";
            }

        }

        return res;

    }

    public static void binarytodec(String s) {
        Long n = Long.parseLong(s);
        Long rem = (long) 0;
        Long ans = (long) 0;
        Long val = (long) 1;

        while (n != 0) {
            rem = n % 10;
            ans = ans + rem * val;
            n = n / 10;
            val = val * 2;

        }

    }
}
