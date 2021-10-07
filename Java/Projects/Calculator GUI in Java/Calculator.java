/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//package Calculator;
import java.awt.*;
import java.awt.event.*;
 
class Calculator extends WindowAdapter implements ActionListener
{
	//Declaring Objects
	Frame f=new Frame();
	Label l1=new Label("First Number, x");
	Label l2=new Label("Second Number, y");
	Label l3=new Label("Result");
	Label credit=new Label();
	
	TextField t1=new TextField("0");
	TextField t2=new TextField("0");
	TextField t3=new TextField();
	
	Button b1=new Button("+");
	Button b2=new Button("-");
	Button b3=new Button("*");
	Button b4=new Button("/");
	Button b5=new Button("sin x");
    Button b6=new Button("cos x");
    Button b7=new Button("tan x");
    Button b8=new Button("Sqrt");
    Button b9=new Button("sinh x");
    Button b10=new Button("cosh");
    Button b11=new Button("tanh x");
    Button b12=new Button("x^y");
	Button b13=new Button("x^2");
    Button b14=new Button("x^3");
    Button b15=new Button("1/x");
    Button b16=new Button("log10(x)");
    Button b17=new Button("ln(x)");
    Button b18=new Button("x!");
    Button b19=new Button("%");
    Button b20=new Button("AC");
	
	public void windowClosing(WindowEvent e) 
	{  
		f.dispose();  
	}  
	
	Calculator()
	{
		//Giving Coordinates
        f.addWindowListener(this);
            
        credit.setBounds(150,50,300,40);
		//cred.set;
        credit.setText("Developed by - 18103076 | Rajan Kataria");
        f.add(credit);
		
		l1.setBounds(100,100,100,25);
		l2.setBounds(100,140,100,25);
		l3.setBounds(100,180,100,25);
		
		t1.setBounds(250,100,150,30);
		t2.setBounds(250,140,150,30);
		t3.setBounds(250,180,150,30);
		t3.setEditable(false);
		
		b1.setBounds(100,280,50,20);
		b2.setBounds(170,280,50,20);
		b3.setBounds(240,280,50,20);
		b4.setBounds(310,280,50,20);
        b5.setBounds(100,310,50,20);
		b6.setBounds(170,310,50,20);
        b7.setBounds(240,310,50,20);
        b8.setBounds(310,310,50,20);
        b9.setBounds(100,340,50,20);
		b10.setBounds(170,340,50,20);
        b11.setBounds(240,340,50,20);
        b12.setBounds(310,340,50,20);
        b13.setBounds(100,370,50,20);
		b14.setBounds(170,370,50,20);
        b15.setBounds(240,370,50,20);
        b16.setBounds(310,370,50,20);
		b17.setBounds(100,400,50,20);
		b18.setBounds(170,400,50,20);
		b19.setBounds(240,400,50,20);
		b20.setBounds(310,400,50,20);
		
		//Adding components to the frame
                
		f.add(l1);
		f.add(l2);
		f.add(l3);
		
		f.add(t1);
		f.add(t2);
		f.add(t3);
		
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		f.add(b6);
		f.add(b7);
        f.add(b8);
		f.add(b9);
        f.add(b10);
        f.add(b11);
        f.add(b12);
        f.add(b13);
        f.add(b14);
        f.add(b15);
        f.add(b16);
		f.add(b17);
		f.add(b18);
		f.add(b19);
		f.add(b20);
                
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);
		b6.addActionListener(this);
		b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
		b10.addActionListener(this);
		b11.addActionListener(this);
		b12.addActionListener(this);
		b13.addActionListener(this);
		b14.addActionListener(this);
		b15.addActionListener(this);
        b16.addActionListener(this);
		b17.addActionListener(this);
		b18.addActionListener(this);
		b19.addActionListener(this);
		b20.addActionListener(this);
		
		f.setLayout(null);
		f.setVisible(true);
		f.setSize(500,500);
		f.setTitle("Scientific Calculator");
	}
	
	public void actionPerformed(ActionEvent e)
	{
		double n1=Double.parseDouble(t1.getText());
        double n2=0;
        if(!t2.getText().equals(""))
            n2=Double.parseDouble(t2.getText());
		
		if(e.getSource()==b1)
		{
			t3.setText(String.valueOf(n1+n2));
		}
			
		if(e.getSource()==b2)
		{
			t3.setText(String.valueOf(n1-n2));
		}
		
		if(e.getSource()==b3)
		{
			t3.setText(String.valueOf(n1*n2));
		}
		
		if(e.getSource()==b4)
		{
			t3.setText(String.valueOf((double)n1/(double)n2));
		}
		
		if(e.getSource()==b5)
		{
			t3.setText(String.valueOf(Math.sin(Math.toRadians(n1))));
		}
        
		if(e.getSource()==b6)
		{
			t3.setText(String.valueOf(Math.cos(Math.toRadians(n1))));
		}
                
        if(e.getSource()==b7)
		{
			t3.setText(String.valueOf(Math.tan(Math.toRadians(n1))));
		}
                
        if(e.getSource()==b8)
		{
			t3.setText(String.valueOf(Math.sqrt(n1)));
		}
		
		if(e.getSource()==b9)
		{
			t3.setText(String.valueOf(Math.sinh(Math.toRadians(n1))));
		}
		
		if(e.getSource()==b10)
		{
			t3.setText(String.valueOf(Math.cosh(Math.toRadians(n1))));
		}
		
		if(e.getSource()==b11)
		{
			t3.setText(String.valueOf(Math.tanh(Math.toRadians(n1))));
		}
                
        if(e.getSource()==b12)
		{
			t3.setText(String.valueOf(Math.pow(n1,n2)));
		}
                
        if(e.getSource()==b13)
		{
			t3.setText(String.valueOf(Math.pow(n1,2)));
		}
                
		if(e.getSource()==b14)
		{
			t3.setText(String.valueOf(Math.pow(n1,3)));
		}
                
        if(e.getSource()==b15)
		{
			t3.setText(String.valueOf(Math.pow(n1,-1)));
        }
        
        if(e.getSource()==b16)
		{
			t3.setText(String.valueOf(Math.log10(n1)));
		}
                
        if(e.getSource()==b17)
		{
			t3.setText(String.valueOf(Math.log(n1)));
		}
                
		if(e.getSource()==b18)
		{
			t3.setText(String.valueOf(getfact(n1)));
		}
                
        if(e.getSource()==b19)
		{
			t3.setText(String.valueOf(n1%n2));
		}
		
		if(e.getSource()==b20)
		{
			t1.setText("0");
			t2.setText("0");
			t3.setText("");
		}
                
	}
	
	public static double getfact(double b)
    {
         if(b==0||b==1)
             return b;
         return b*getfact(b-1);
    }
	
	public static void main(String[] args)
	{
		new Calculator();
	}
}

/*import java.awt.*;
import java.awt.event.*;
 
class Calculator implements ActionListener
{
	//Declaring Objects
	Frame f=new Frame();
	Label l1=new Label("First Number");
	Label l2=new Label("Second Number");
	Label l3=new Label("Result");
	
	TextField t1=new TextField();
	TextField t2=new TextField();
	TextField t3=new TextField();
	
	Button b1=new Button("Add");
	Button b2=new Button("Sub");
	Button b3=new Button("Mul");
	Button b4=new Button("Div");
	Button b5=new Button("Cancel");
	
	Calculator()
	{
		//Giving Coordinates
		l1.setBounds(50,100,100,20);
		l2.setBounds(50,140,100,20);
		l3.setBounds(50,180,100,20);
		
		t1.setBounds(200,100,100,20);
		t2.setBounds(200,140,100,20);
		t3.setBounds(200,180,100,20);
		
		b1.setBounds(50,250,50,20);
		b2.setBounds(110,250,50,20);
		b3.setBounds(170,250,50,20);
		b4.setBounds(230,250,50,20);
		b5.setBounds(290,250,50,20);
		
		//Adding components to the frame
		f.add(l1);
		f.add(l2);
		f.add(l3);
		
		f.add(t1);
		f.add(t2);
		f.add(t3);
		
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);
		
		f.setLayout(null);
		f.setVisible(true);
		f.setSize(400,350);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		int n1=Integer.parseInt(t1.getText());
		int n2=Integer.parseInt(t2.getText());
		
		if(e.getSource()==b1)
		{
			t3.setText(String.valueOf(n1+n2));
		}
			
		if(e.getSource()==b2)
		{
			t3.setText(String.valueOf(n1-n2));
		}
		
		if(e.getSource()==b3)
		{
			t3.setText(String.valueOf(n1*n2));
		}
		
		if(e.getSource()==b4)
		{
			t3.setText(String.valueOf(n1/n2));
		}
		
		if(e.getSource()==b5)
		{
			System.exit(0);
		}
	}
	
	public static void main(String...s)
	{
		new Calculator();
	}
}*/