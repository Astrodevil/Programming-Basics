// Write a function that given an array of integers, return the first duplicate number for which the second occurrence has the minimal index. If no duplicates can be found, return -1.

function firstDuplicate(array) {
    const seen = {};

    for (let i = 0; i < array.length; i++) {
        if (seen[array[i]] !== undefined) return array[i];
        else seen[array[i]] = array[i];
    };
    
    return -1;
};
