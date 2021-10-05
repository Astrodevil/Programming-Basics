For running the program in IntelliJ IDEA:

Since it is a JavaFX program, We need to setup accordingly (following steps are for windows):


1) Download the openjfx-17.0.0.1_windows-x86_bin-sdk zip file and extract it. Remeber its location.

2) Go to File> Settings> Appearance & Beahvior > Path Variables

3) Add Name=PATH_TO_FX with Value=[Download location]\openjfx-17.0.0.1_windows-x86_bin-sdk\javafx-sdk-17.0.0.1\lib

see image below:

![alt text](https://raw.githubusercontent.com/sushant-sinha/Programming-Basics/5259b41bc9c880251e7a16c323592e9480a139c3/Java/Simple%20Games/Color%20Game/path%20variable%20setting.PNG)

4) Go to File> Project Structure> Libraries. Add [Download location]\openjfx-17.0.0.1_windows-x86_bin-sdk\javafx-sdk-17.0.0.1\lib

see image below:

![alt text](https://raw.githubusercontent.com/sushant-sinha/Programming-Basics/5259b41bc9c880251e7a16c323592e9480a139c3/Java/Simple%20Games/Color%20Game/adding%20javafx%20library.PNG)

5) Now Go to Run>Edit Configurations and create a new confiugration. Replace [Directory Location] with your working directory location.

see image below:

![alt text](https://raw.githubusercontent.com/sushant-sinha/Programming-Basics/5259b41bc9c880251e7a16c323592e9480a139c3/Java/Simple%20Games/Color%20Game/run%20configuration.PNG)

You are all set!!

Rules:

See the color of the text in the top of the screen.

Match it with the text showing that color


Final Result:

![alt text](https://raw.githubusercontent.com/sushant-sinha/Programming-Basics/0ddd984dd3a56fa1a170bee0e9299fc5aec92227/Java/Simple%20Games/Color%20Game/ss.PNG)