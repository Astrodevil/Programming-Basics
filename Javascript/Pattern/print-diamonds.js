// Write a function that prints a Diamond to the console by returning a single string, using the asterisk (*) character as the printable character.
// Remove trailing spaces and finish every line with a ‘\n’.
// Return null / None if the input is an even number or negative.

function diamond(n){
  if (n < 1 || n % 2 === 0) return null;
  
  let string = '';
  const middle = Math.round(n / 2);
  
  for (let i = 1; i <= n; i++) {
    const spaces = Math.abs(Math.floor((i - middle)));
    const stars = n - (spaces * 2);
    string += ' '.repeat(spaces) + '*'.repeat(stars) + '\n';
  };
  
  return string;
};
