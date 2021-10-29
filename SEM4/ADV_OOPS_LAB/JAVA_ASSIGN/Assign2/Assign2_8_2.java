package java_assignments2;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.lang.String;
import java.util.Scanner;

class GUI implements ActionListener
{
    JFrame f=new JFrame("Employee Search");
    private JLabel label;
    private JTextField textField;
    private  JButton button;
    private JTextArea field;
    GUI()
    {
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(800,500);
        f.setVisible(true);
        f.setLocation(300,100);
        f.setLayout(null);
//        f.setResizable(false);

        label=new JLabel("Employee Code");
        label.setFont(new Font("Arial",Font.PLAIN,15));
        label.setBounds(100,50,200,20);
        f.getContentPane().add(label);

        textField=new JTextField();
        textField.setFont(new Font("Arial",Font.PLAIN,15));
        textField.setSize(100,20);
        textField.setLocation(230,50);
        f.getContentPane().add(textField);

        button=new JButton("Search");
        button.setBounds(250,80,100,30);
        button.setFont(new Font("Arial",Font.PLAIN,15));
        f.getContentPane().add(button);
        button.addActionListener(this);

        field=new JTextArea();
        field.setSize(600,300);
        field.setLocation(50,120);
        field.setFont(new Font("Arial",Font.PLAIN,15));
        field.setEditable(false);
        field.setLineWrap(true);
        f.getContentPane().add(field);


    }
     String searchFile(String id) throws IOException
    {
        FileReader f=new FileReader("Employee1.txt");
        Scanner scn=new Scanner(f);
        File file=new File("Employee1.txt");
        if(file.exists())
        {
            while(scn.hasNextLine())
            {
                String line=scn.nextLine();
                if(line.contains(id))
                {
                    f.close();
                    return line;
                }
            }
            f.close();
            return "NotFound";

        }
        f.close();
        return "NotExists";
    }
    @Override
    public void actionPerformed(ActionEvent e) {

           if(e.getSource()==button)
           {
              try {
                  String str=searchFile(textField.getText());
                  if(str.equals("NotFound"))
                  {
                      JOptionPane.showMessageDialog(f,"Data Not found","Message",JOptionPane.WARNING_MESSAGE);
                      field.setText("The Employee doesn't exist for the entered employee code");
                  }

                  else if(str.equals("NotExists"))
                  {
                       JOptionPane.showMessageDialog(f,"File Not Found","Message",JOptionPane.WARNING_MESSAGE);
                  }
                  else
                  {
                      FileWriter fr=new FileWriter("Data.txt",true);
                      JOptionPane.showMessageDialog(f,"Data Found!","Message",JOptionPane.INFORMATION_MESSAGE);
                      fr.write(str);
                      fr.write(System.lineSeparator());
                      field.setText(str);
                      fr.close();
                  }

              }
              catch (Exception e1)
              {
                  e1.printStackTrace();
              }
           }
    }
}

public class Assign2_8_2 {
    public static void main(String[] args) throws Exception {
      GUI g=new GUI();
    }
}
