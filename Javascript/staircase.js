// Write a function that prints a staircase to the console.
// Your function should accept an integer and print ‘#’ as the stair character.

function staircase(width) { 
    for (let i = 1; i <= width; i++) {
        let j = i;
        let string = '';  
        for (let j = i; j < width; j++) string += ' ';
        for (let k = 0; k < i; k++) string += '#';  
        console.log(string);
    };
};

staircase(10);
