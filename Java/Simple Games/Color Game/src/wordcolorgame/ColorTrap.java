package wordcolorgame;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.text.*;
import javafx.scene.text.Font;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.util.Duration;


public class ColorTrap extends Application
{
    private Scene scene;
    private BorderPane borderPane;
    private Text txtCountDown;
    private Text trap;
    private String rColor;
    private Text choice;
    private Text scoreT;
    private int score;
    private final ColorsEnum colors[] = ColorsEnum.values();
    private final List<String> list = new ArrayList(Arrays.asList(colors));
    private final Text opt[] = new Text[list.size()];
    private ImageView img = new ImageView();
    private final Image check = new Image("wordcolorgame/correct.png");
    private final Image x = new Image("wordcolorgame/wrong.png");

    private Timeline timeline;

    private final int TIMER = 15;
    private int count = 0;

    @Override
    public void start(Stage primaryStage)
    {
        borderPane = new BorderPane();
        borderPane.setStyle("-fx-background-color: lightgrey");
        scene = new Scene(borderPane, 800, 800);
        primaryStage.setMinHeight(300);
        primaryStage.setMinWidth(600);
        initializeGame();
        startPlay();

        primaryStage.setTitle("Color Confuser");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

     public void startPlay()
   {
         chooseTrapWordAndColor();
         colorNameOptions();
         
         count = TIMER;
         txtCountDown.setText(TIMER + "");
         timeline = new Timeline(new KeyFrame(
         Duration.millis(1000), e -> {
         
         
         if(count >= 0)
         {
         txtCountDown.setText(count + "");
         count--;
         }
         else
         {
         endOfGame();                     }
         }));
         timeline.setCycleCount(TIMER + 2);
         timeline.play();
 
     }
    
    public void endOfGame()
    {       
        borderPane.getChildren().clear();
        Text fScore = new Text("Your score: " + score);
        fScore.setFont(Font.font("Marker Felt", 40));
        
        Button play = new Button("Play again");   
        play.setOnAction(e -> {
            score = 0;
            initializeGame();
            startPlay();
        });

        VBox end = new VBox(20,fScore, play);
        end.setAlignment(Pos.CENTER);
        borderPane.setCenter(end);
    }
    
    
    public void checkChoice(Text choice)
    {
        if(this.choice.getText().equals(rColor)){
            score++;
            scoreT.setText("Score: " + score);
            img.setImage(check);
        }
        else{
            img.setImage(x);
        }
        chooseTrapWordAndColor();
        colorNameOptions();
    }

    public void chooseTrapWordAndColor()
    {
        Random rando = new Random();
        int size = colors.length;
        int n = rando.nextInt(colors.length);
        
        trap.setText(colors[n].name());

        rColor = colors[rando.nextInt(size)].name();
        trap.setFill(Color.valueOf(rColor));
    }
    
    public void colorNameOptions()
    {
        Collections.shuffle(list);
        for(int i = 0; i < colors.length; i++){
            opt[i].setText(String.valueOf(list.get(i)));           
        }
        Collections.shuffle(list);
        for(int i = 0; i < colors.length; i++){
            opt[i].setFill(Color.valueOf(String.valueOf(list.get(i))));           
        }
 
        for (Text opt1 : opt) {
            String s = opt1.getText();
            choice = new Text();
            opt1.setOnMouseClicked((MouseEvent e) -> {
                choice.setText(s);
                checkChoice(choice);
            });
        }  
    }

    public void initializeGame()
    {
        trap = new Text();
        trap.setFont(Font.font("Marker Felt", 60));
        
        borderPane.setTop(trap);
        BorderPane.setAlignment(trap, Pos.CENTER);
        
        
        
        FlowPane optionHolder = new FlowPane(Orientation.HORIZONTAL, 10, 10);
        optionHolder.setAlignment(Pos.CENTER);

        for(int i = 0; i < list.size(); i++){
            String s = String.valueOf(list.get(i));
            opt[i] = new Text(s);
            opt[i].setFont(Font.font("Marker Felt", 40));
            optionHolder.getChildren().add(opt[i]);
        }   

        borderPane.setCenter(optionHolder);
        BorderPane.setAlignment(optionHolder, Pos.CENTER);
        BorderPane.setMargin(optionHolder, new Insets(0,80,0,80));

        
        
        scoreT = new Text("Score: " + score);
        scoreT.setFont(Font.font(20));

        Region region1 = new Region();
        HBox.setHgrow(region1, Priority.ALWAYS);
        
        img = new ImageView();
        img.setFitWidth(30);
        img.setFitHeight(30);
        
        Region region2 = new Region();
        HBox.setHgrow(region2, Priority.ALWAYS);
  
        Text t = new Text("Time: ");
        t.setFont(Font.font(20));
        txtCountDown = new Text();       
        txtCountDown.setFont(Font.font(20));
        HBox right = new HBox(t, txtCountDown);

        HBox statusbar = new HBox(scoreT, region1, img, region2, right);

        borderPane.setBottom(statusbar);
        BorderPane.setAlignment(statusbar, Pos.CENTER);
    }
    public static void main(String[] args)
    {
        launch(args);
    }
}